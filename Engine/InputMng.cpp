#include "InputMng.h"
#include "Headers.h"


InputMng::InputMng()
{
	for (int i = 0; i < 500; i++)
	{
		isKeyDown[i] = false;
		isKeyKeepDown[i] = false;
		isKeyUp[i] = false;

		isKeyFirstDown[i] = true;
		isKeyFirstUp[i] = true;
	}
}


InputMng::~InputMng()
{
}

void InputMng::ProcKeys()
{
	for (int i = 0; i < 500; i++)
	{
		if (GetAsyncKeyState(i))
		{
			isKeyDown[i] = isKeyFirstDown[i];
			isKeyKeepDown[i] = true;
			isKeyUp[i] = false;

			isKeyFirstDown[i] = false;
			isKeyFirstUp[i] = true;
		}
		else
		{
			isKeyDown[i] = false;
			isKeyKeepDown[i] = false;
			isKeyUp[i] = isKeyFirstUp[i];

			isKeyFirstDown[i] = true;
			isKeyFirstUp[i] = false;
		}
	}
}

bool InputMng::GetKeyDown(int _vk)
{
	return isKeyDown[_vk];
}

bool InputMng::GetKeyKeepDown(int _vk)
{
	return isKeyKeepDown[_vk];
}

bool InputMng::GetKeyUp(int _vk)
{
	return isKeyUp[_vk];
}
