#pragma once
#include "GameObject.h"

class Sprite : public GameObject
{
public:
	Sprite(string _path);
	virtual ~Sprite();
};

