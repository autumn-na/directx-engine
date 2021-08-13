#pragma once
#include "GameObject.h"

class Button : public GameObject
{
public:
	Button(string _normalPath, string _hoveringPath, string _keepDownPath, function<void(void)> _upEvent);
	virtual ~Button();
};

