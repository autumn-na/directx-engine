#include "GameObjectMng.h"
#include "SceneMng.h"


GameObjectMng::GameObjectMng()
{
	nextID = 0;
}


GameObjectMng::~GameObjectMng()
{
}

void GameObjectMng::ProcDestroyObject()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->isAlive == false)
		{
			delete gameObjects[i];

			gameObjects.erase(gameObjects.begin() + i);

			i--;
		}
	}
}

void GameObjectMng::ProcUpdateAll()
{
	for (int i_layer = SceneMng::Layer::END - 1; i_layer >= 0; i_layer--)
	{
		for (int j_obj = 0; j_obj < gameObjects.size(); j_obj++)
		{
			if (gameObjects[j_obj]->layer == i_layer)
			{
				gameObjects[j_obj]->Update();
			}
		}
	}
}
void GameObjectMng::ProcRenderAll()
{
	for (int i_layer = 0; i_layer < SceneMng::Layer::END; i_layer++)
	{
		for (int j_obj = 0; j_obj < gameObjects.size(); j_obj++)
		{
			if (gameObjects[j_obj]->layer == i_layer)
			{
				gameObjects[j_obj]->Render();
			}
		}
	}
}

void GameObjectMng::AddObject(GameObject * _obj)
{
	gameObjects.push_back(_obj);

	_obj->ID = nextID;
	nextID++;
}

void GameObjectMng::ReleaseObject(GameObject * _obj)
{
	_obj->isAlive = false;
}

void GameObjectMng::ReleaseAll()
{
	for(int i = 0;i < gameObjects.size(); i++)
	{
		gameObjects[i]->isAlive = false;
	}
}

bool GameObjectMng::CheckIsID(int _ID)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->ID == _ID)
			return true;
	}

	return false;
}
