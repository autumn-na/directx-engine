#include "Scene.h"
#include "GameObjectMng.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::Release()
{
	GameObjectMng::GetInstance()->ReleaseAll();
}
