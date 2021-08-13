#pragma once
#include "Scene.h"


class InGameScene : public Scene
{
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Init();
	virtual void Update();
};

