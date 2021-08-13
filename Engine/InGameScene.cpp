#include "InGameScene.h"
#include "SceneMng.h"
#include "PopUp.h"
#include "Cut.h"

InGameScene::InGameScene()
{
}


InGameScene::~InGameScene()
{
}

void InGameScene::Init()
{
	Button* btTest = new Button("Resources/Test/bt_normal.png", "Resources/Test/bt_hovering.png", "Resources/Test/bt_click.png", []()->void {cout << "fuck" << endl; });
	btTest->pos = Vec2(200, 200);
	btTest->Wiggle();

	Button* btTest2 = new Button("Resources/Test/bt_normal.png", "", "", []()->void {cout << "fuck" << endl; });
	btTest2->pos = Vec2(200, 450);

	Effect* efTest1 = new Effect(2.f, "Resources/Test/ef_0.png", false);
	efTest1->pos = Vec2(390, 200);

	Effect* efTest2 = new Effect(2.f, "Resources/Test/ef_0.png", true);
	efTest2->pos = Vec2(600, 200);

	Effect* efTest3 = new Effect(0.5f, "Resources/Test/ef_0.png", 3);
	efTest3->pos = Vec2(800, 200);

	Effect* efTest4 = new Effect(2.f, "Resources/Test/ef_0.png", 1.0f);
	efTest4->pos = Vec2(1000, 200);


	Timer* tmTest = new Timer();
	tmTest->SetTimer(1.0f, 10, []()->void {cout << "test!" << endl; });

	Timer* tmTest2 = new Timer();
	tmTest2->SetTimer(10.0f, false, [this]()->void {SceneMng::GetInstance()->ChangeScene(SceneMng::SceneCode::IN_GAME); });

	Timer* tmTest3 = new Timer();
	tmTest3->SetTimer(1.0f, false, []()->void {cout << "test true!" << endl; });

	SoundMng::GetInstance()->PlayFX("Resources/Test/test.wav");

	ProgressBar* progress = new ProgressBar("Resources/Test/gauge.png", ProgressBar::FillType::LEFT);
	progress->pos = Vec2(1500, 300);
	progress->SetProgress(100);

	PopUp* popup = new PopUp();

	//Cut* cut = new Cut("Resources/Test/Cut/_0.png", nullptr);
}

void InGameScene::Update()
{
}
