#pragma once
#include "GameObject.h"
class Timer : public GameObject
{
public:
	bool canRun;
	float startTime;

	float delay;
	bool isLoop;
	int count;
	function<void(void)> event;


	Timer();
	virtual ~Timer();

	virtual void Update();

	void ProcRun();

	void SetTimer(float _delay, bool _isLoop, function<void(void)> _event);
	void SetTimer(float _delay, int _count, function<void(void)> _event);
};

