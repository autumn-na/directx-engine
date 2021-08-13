#pragma once
#include "Singleton.h"

class InputMng : public Singleton<InputMng>
{
public:
	bool isKeyDown[500];
	bool isKeyKeepDown[500];
	bool isKeyUp[500];

	bool isKeyFirstDown[500];
	bool isKeyFirstUp[500];



	InputMng();
	virtual ~InputMng();

	void ProcKeys();

	bool GetKeyDown(int _vk);
	bool GetKeyKeepDown(int _vk);
	bool GetKeyUp(int _vk);
};

