#include "GameObject.h"
#include "GraphicMng.h"
#include "TextureMng.h"
#include "InputMng.h"
#include "Camera.h"
#include "Time.h"
#include "SceneMng.h"
#include "GameObjectMng.h"

GameObject::GameObject()
{
	ID = -1;

	isAlive = true;
	isVisible  = true;

	pos = Vec2(0, 0);
	pivot = Vec2(0.5f, 0.5f);
	scale = Vec2(1.0f, 1.0f);
	degree = 0.f;

	color = D3DXCOLOR(1, 1, 1, 1);
	SetRectEmpty(&size);
	texture = NULL;

	layer = 0;

	curFrame = 0;
	lastFrameTime = 0;
	lastPath = "";

	canEnter = true;
	canClick = false;

	update = nullptr;
	destroy = nullptr;

	onMouseNothing = nullptr;
	onMouseEnter = nullptr;
	onMouseHovering = nullptr;
	onMouseDown = nullptr;
	onMouseKeepDown = nullptr;
	onMouseUp = nullptr;
	onMouseExit = nullptr;

	GameObjectMng::GetInstance()->AddObject(this);
}

GameObject::~GameObject()
{
	if (destroy != nullptr)
		destroy;
}

void GameObject::Update()
{
	if (update != nullptr)
		update();

	if (ProcCheckCanMouse() == true)
	{
		ProcMouseNothing();
		ProcMouseEnter();
		ProcMouseHovering();
		ProcMouseDown();
		ProcMouseKeepDown();
		ProcMouseUp();
		ProcMouseExit();
	}
}

void GameObject::Render()
{
	if (isVisible == false ||
		isAlive == false)
		return;

	D3DXMATRIX mat;
	D3DXMATRIX pos;
	D3DXMATRIX rot;
	D3DXMATRIX scale;
	D3DXMATRIX center;
	D3DXMATRIX centerI;

	D3DXMatrixIdentity(&mat);
	D3DXMatrixIdentity(&pos);
	D3DXMatrixIdentity(&rot);
	D3DXMatrixIdentity(&scale);
	D3DXMatrixIdentity(&center);
	D3DXMatrixIdentity(&centerI);

	if( layer == SceneMng::Layer::LOWER_UI ||
		layer == SceneMng::Layer::UI || 
		layer == SceneMng::Layer::UPPER_UI)
		D3DXMatrixTranslation(&pos, this->pos.x, this->pos.y, 0);
	else
		D3DXMatrixTranslation(&pos, 960 - Camera::pos.x + this->pos.x, 540 - Camera::pos.y + this->pos.y, 0);
	D3DXMatrixRotationZ(&rot, D3DXToRadian(degree));
	D3DXMatrixScaling(&scale, this->scale.x, this->scale.y, 1);
	D3DXMatrixInverse(&centerI, NULL, &center);
	D3DXMatrixTranslation(&centerI, -(size.right - size.left) * pivot.x, -(size.bottom - size.top) * pivot.y, 0);
	
	mat = centerI * scale * rot * center * pos;

	GraphicMng::GetInstance()->d3dxSprite->SetTransform(&mat);
	GraphicMng::GetInstance()->d3dxSprite->Begin(D3DXSPRITE_ALPHABLEND);
	GraphicMng::GetInstance()->d3dxSprite->Draw(texture, &size, NULL, NULL, color);
	GraphicMng::GetInstance()->d3dxSprite->End();
}

void GameObject::ProcMouseNothing()
{
	if (canEnter == true &&
		canClick == false &&
		CheckIsInVec2(GraphicMng::GetInstance()->GetMousePos()) == false)
	{
		canEnter = true;
		canClick = false;

		if (onMouseNothing != nullptr)
			onMouseNothing();
	}
}

void GameObject::ProcMouseEnter()
{
	if (canEnter == true &&
		canClick == false &&
		CheckIsInVec2(GraphicMng::GetInstance()->GetMousePos()) == true)
	{
		canEnter = false;
		canClick = true;

		if (onMouseEnter != nullptr)
			onMouseEnter();
	}
}

void GameObject::ProcMouseHovering()
{
	if (canEnter == false &&
		canClick == true &&
		CheckIsInVec2(GraphicMng::GetInstance()->GetMousePos()) == true)
	{
		canEnter = false;
		canClick = true;

		if (onMouseHovering != nullptr)
			onMouseHovering();
	}
}

void GameObject::ProcMouseDown()
{
	if (canEnter == false &&
		canClick == true &&
		CheckIsInVec2(GraphicMng::GetInstance()->GetMousePos()) == true &&
		InputMng::GetInstance()->GetKeyDown(VK_LBUTTON) == true)
	{
		canEnter = false;
		canClick = false;

		if (onMouseDown != nullptr)
			onMouseDown();
	}
}

void GameObject::ProcMouseKeepDown()
{
	if (canEnter == false &&
		canClick == false &&
		CheckIsInVec2(GraphicMng::GetInstance()->GetMousePos()) == true &&
		InputMng::GetInstance()->GetKeyKeepDown(VK_LBUTTON) == true)
	{
		canEnter = false;
		canClick = false;

		if (onMouseKeepDown != nullptr)
			onMouseKeepDown();
	}
}

void GameObject::ProcMouseUp()
{
	if (canEnter == false &&
		canClick == false &&
		CheckIsInVec2(GraphicMng::GetInstance()->GetMousePos()) == true &&
		InputMng::GetInstance()->GetKeyUp(VK_LBUTTON) == true)
	{
		canEnter = false;
		canClick = true;

		if (onMouseUp != nullptr)
			onMouseUp();
	}
}

void GameObject::ProcMouseExit()
{
	if (canEnter == false &&
		CheckIsInVec2(GraphicMng::GetInstance()->GetMousePos()) == false)
	{
		canEnter = true;
		canClick = false;

		if (onMouseExit != nullptr)
			onMouseExit();
	}
}

bool GameObject::ProcCheckCanMouse()
{
	if (isVisible == false ||
		isAlive == false)
		return false;

	for (int i_layer = layer; i_layer < SceneMng::Layer::END; i_layer++)
	{
		for (int j_obj = 0; j_obj < GameObjectMng::GetInstance()->gameObjects.size(); j_obj++)
		{
			if (GameObjectMng::GetInstance()->gameObjects[j_obj]->layer == layer &&
				GameObjectMng::GetInstance()->gameObjects[j_obj]->ID > ID &&
				GameObjectMng::GetInstance()->gameObjects[j_obj]->CheckIsInVec2(GraphicMng::GetInstance()->GetMousePos()) == true)
				return false;

			if (GameObjectMng::GetInstance()->gameObjects[j_obj]->layer > layer &&
				GameObjectMng::GetInstance()->gameObjects[j_obj]->CheckIsInVec2(GraphicMng::GetInstance()->GetMousePos()) == true)
				return false;
		}
	}

	return true;
}

bool GameObject::Animation(float _delay, string _path, bool _isLoop)
{
	if (curFrame == 0 &&
		lastPath == "")
		curFrame + 1;

	if (GetTickCount() >= lastFrameTime + _delay * 1000 / Time::timeScale)
	{
		if (lastPath != _path)
			canPlay = true;

		if (canPlay == false)
			return false;

		string __nextPath = _path;

		for (int i = __nextPath.size() - 1; i >= 0; i--)
		{
			if (__nextPath.at(i) == '_')
				break;

			__nextPath.pop_back();
		}

		__nextPath += to_string(curFrame) + ".png";

		if (TextureMng::GetInstance()->LoadTexture(__nextPath) == NULL)
		{
			curFrame = 0;

			canPlay = _isLoop;

			return false;
		}

		SetTexture(__nextPath);

		lastFrameTime = GetTickCount();

		curFrame++;
	}

	return true;
}

bool GameObject::CheckIsInVec2(Vec2 _vec)
{
	if (abs(_vec.x - pos.x) <= size.right / 2 &&
		abs(_vec.y - pos.y) <= size.bottom / 2)
		return true;
	else
		return false;
}

void GameObject::SetTexture(string _path)
{
	texture = TextureMng::GetInstance()->LoadTexture(_path);
	SetRect(&size, 0, 0, TextureMng::GetInstance()->LoadImageInfo(_path).Width, TextureMng::GetInstance()->LoadImageInfo(_path).Height);
}

void GameObject::Wiggle()
{
	//update = [this]()->void
	//{
	//	scale.x = 1 + cos(wiggleCount) / 2.f;
	//	scale.y = 1 + cos(wiggleCount) / 2.f;
	//	wiggleCount += 0.1f;
	//};
	
	auto preUpdate = update;

	update = [=]() -> void
	{
		if (preUpdate)
		{
			preUpdate();
		}

		scale.x = 1 + cos(wiggleCount) / 2.f;
		scale.y = 1 + cos(wiggleCount) / 2.f;
		wiggleCount += 0.1f;
	};
}