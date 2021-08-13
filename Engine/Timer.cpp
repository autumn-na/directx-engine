#include "Timer.h"
#include "Time.h"


Timer::Timer()
{
	canRun = false;
	startTime = 0;

	delay = 0;
	isLoop = false;
	count = 1;
	event = nullptr;
}


Timer::~Timer()
{
}

void Timer::Update()
{
	GameObject::Update();

	ProcRun();
}

void Timer::ProcRun()
{
	if (canRun == false)
		return;

	if (GetTickCount() >= startTime + delay * 1000 / Time::timeScale)
	{
		if(event != nullptr)
			event();

		if (isLoop == true)
		{
			startTime = GetTickCount();
		}
		else
		{
			count--;

			if (count == 0)
				canRun = false;
		}
	}
}

void Timer::SetTimer(float _delay, bool _isLoop, function<void(void)> _event)
{
	canRun = true;
	startTime = GetTickCount();

	delay = _delay;
	isLoop = _isLoop;
	count = 1;
	event = _event;
}

void Timer::SetTimer(float _delay, int _count, function<void(void)> _event)
{
	canRun = true;
	startTime = GetTickCount();

	delay = _delay;
	isLoop = false;
	count = _count;
	event = _event;
}
