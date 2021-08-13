#pragma once
#include "GameObject.h"
#include "Sprite.h"

class PopUp :
	public GameObject
{
public:
	PopUp();
	virtual ~PopUp();
	 
	Sprite* spr;

	virtual void Update();
};

