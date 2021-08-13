#pragma once
#include "Singleton.h"
#include "Scene.h"

class SceneMng : public Singleton<SceneMng>
{
public:
	enum Layer
	{
		DEFAULT,
		LOWER_UI,
		UI,
		UPPER_UI,
		END
	};

	enum SceneCode
	{
		IN_GAME
	};

	Scene* curScene;
	Scene* nextScene;



	SceneMng();
	virtual ~SceneMng();

	void ProcChangeScene();
	void ChangeScene(SceneCode _code);
};

