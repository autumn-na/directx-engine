#include "Cut.h"
#include "InputMng.h"
#include "TextureMng.h"
#include "GameObjectMng.h"

Cut::Cut(string _path, function<void(void)> _event)
{
	path = _path;
	event = _event;

	pos = Vec2(960, 540);

	SetTexture(_path);
}

Cut::~Cut()
{
}

void Cut::Update()
{
	if (InputMng::GetInstance()->GetKeyDown(VK_SPACE))
	{
		curFrame++;

		string __nextPath = path;

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

			if (event != nullptr)
				event();

			GameObjectMng::GetInstance()->ReleaseObject(this);
		}

		SetTexture(__nextPath);
	}
}
