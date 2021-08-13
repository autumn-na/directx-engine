#include "SceneMng.h"
#include "Headers.h"
#include "InGameScene.h"

SceneMng::SceneMng()
{
	curScene = NULL;
	nextScene = NULL;
}


SceneMng::~SceneMng()
{
}

void SceneMng::ProcChangeScene()
{
	if (nextScene != NULL)
	{
		if (curScene != NULL)
			curScene->Release();

		curScene = nextScene;
		curScene->Init();
		
		nextScene = NULL;
	}
}

void SceneMng::ChangeScene(SceneCode _code)
{
	switch (_code)
	{
	case SceneMng::IN_GAME:
		nextScene = new InGameScene();
		break;
	default:
		break;
	}
}
