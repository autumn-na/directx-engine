#include "PopUp.h"
#include "GameObjectMng.h"


PopUp::PopUp()
{
	pos = Vec2(-1000, 250);

	SetTexture("Resources/Test/pop_up.png");
}


PopUp::~PopUp()
{
}

void PopUp::Update()
{
	GameObject::Update();

	D3DXVec2Lerp(&pos, &pos, &Vec2(960, 250), 0.1f);

	if (pos.x > 950)
		D3DXColorLerp(&color, &color, &D3DXCOLOR(1.f, 1, 1, 0), 0.1f);

	if (color.a < 0.1f)
		GameObjectMng::GetInstance()->ReleaseObject(this);
}
