#include "Effect.h"
#include "GameObjectMng.h"


Effect::Effect(float _delay, string _path)
{
	delay = _delay;
	path = _path;

	count = 1;
	aliveTime = 0;

	tmToRelease = new Timer();
}

Effect::Effect(float _delay, string _path, int _count)
{
	delay = _delay;
	path = _path;

	count = _count;
	aliveTime = 0;

	tmToRelease = new Timer();
}

Effect::Effect(float _delay, string _path, float _aliveTime)
{
	delay = _delay;
	path = _path;

	count = INFINITE;
	aliveTime = _aliveTime;

	tmToRelease = new Timer();
	tmToRelease->SetTimer(aliveTime, false, [=]()->void
	{
		GameObjectMng::GetInstance()->ReleaseObject(this);
	});
}

Effect::~Effect()
{
	GameObjectMng::GetInstance()->ReleaseObject(tmToRelease);
}

void Effect::Update()
{
	if (Animation(delay, path, false) == false)
	{
		count--;

		if (count == 0)
			GameObjectMng::GetInstance()->ReleaseObject(this);
	}
}
