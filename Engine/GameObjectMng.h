#pragma once
#include "Singleton.h"
#include "GameObject.h"

class GameObjectMng : public Singleton<GameObjectMng>
{
public:
	vector<GameObject*> gameObjects;

	int nextID;



	GameObjectMng();
	virtual ~GameObjectMng();

	void ProcDestroyObject();
	void ProcUpdateAll();
	void ProcRenderAll();

	void AddObject(GameObject* _obj);
	void ReleaseObject(GameObject* _obj);
	void ReleaseAll();

	bool CheckIsID(int _ID);
};

