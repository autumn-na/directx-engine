#include "System.h"
#include "Headers.h"
#include "GraphicMng.h"
#include "TextureMng.h"
#include "InputMng.h"
#include "GameObjectMng.h"
#include "SceneMng.h"

System::System()
{
}


System::~System()
{
}

void System::Init()
{
	GraphicMng::GetInstance()->Init();
	SceneMng::GetInstance()->ChangeScene(SceneMng::SceneCode::IN_GAME);
}

void System::MsgLoop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			DispatchMessage(&msg);
			TranslateMessage(&msg);
		}
		else
		{
			MainLoop();
		}
	}
}

void System::MainLoop()
{
	InputMng::GetInstance()->ProcKeys();
	SceneMng::GetInstance()->ProcChangeScene();
	GameObjectMng::GetInstance()->ProcDestroyObject();
	GameObjectMng::GetInstance()->ProcUpdateAll();
	SceneMng::GetInstance()->curScene->Update();
	GraphicMng::GetInstance()->RenderStart();
	GameObjectMng::GetInstance()->ProcRenderAll();
	GraphicMng::GetInstance()->RenderEnd();
}

void System::Release()
{
	SceneMng::GetInstance()->curScene->Release();
	TextureMng::GetInstance()->ReleaseAll();
	GraphicMng::GetInstance()->Release();
}
