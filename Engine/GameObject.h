#pragma once

#include "Headers.h"

class GameObject
{
public:
	int ID;

	bool isAlive;
	bool isVisible;

	Vec2 pos;
	Vec2 pivot;
	Vec2 scale;
	float degree;

	RECT size;
	Texture texture;
	D3DXCOLOR color;

	int layer;

	bool canPlay;
	int curFrame;
	float lastFrameTime;
	string lastPath;

	bool canEnter;
	bool canClick;

	float wiggleCount;

	function<void(void)> update;
	function<void(void)> destroy;

	function<void(void)> onMouseNothing;
	function<void(void)> onMouseEnter;
	function<void(void)> onMouseHovering;
	function<void(void)> onMouseDown;
	function<void(void)> onMouseKeepDown;
	function<void(void)> onMouseUp;
	function<void(void)> onMouseExit;



	GameObject();
	virtual ~GameObject();

	virtual void Update();
	virtual void Render();

	void ProcMouseNothing();
	void ProcMouseEnter();
	void ProcMouseHovering();
	void ProcMouseDown();
	void ProcMouseKeepDown();
	void ProcMouseUp();
	void ProcMouseExit();

	bool ProcCheckCanMouse();

	bool Animation(float _delay, string _path, bool _isLoop);

	bool CheckIsInVec2(Vec2 _vec);

	void SetTexture(string _path);

	void Wiggle();
};

