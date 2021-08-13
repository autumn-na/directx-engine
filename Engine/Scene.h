#pragma once

#include "DataMng.h"
#include "GameObjectMng.h"
#include "GraphicMng.h"
#include "InputMng.h"
#include "SoundMng.h"
#include "TextureMng.h"

#include "Button.h"
#include "Effect.h"
#include "ProgressBar.h"
#include "Sprite.h"
#include "Timer.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init() = 0;
	virtual void Update() = 0;

	void Release();
};

