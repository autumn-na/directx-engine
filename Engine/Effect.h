#pragma once
#include "GameObject.h"
#include "Timer.h"

class Effect : public GameObject
{
public:
	float delay;
	string path;

	int count;
	float aliveTime;

	Timer* tmToRelease;


	Effect(float _delay, string _path);
	Effect(float _delay, string _path, int _count);
	Effect(float _delay, string _path, float _aliveTime);
	virtual ~Effect();

	virtual void Update();
};

