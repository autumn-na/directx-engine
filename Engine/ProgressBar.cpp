#include "ProgressBar.h"
#include "Time.h"


ProgressBar::ProgressBar(string _path, FillType _fillType)
{
	SetTexture(_path);

	fillType = _fillType;

	switch (fillType)
	{
	case ProgressBar::UP:
		pivot = Vec2(0.5f, 0);
		break;
	case ProgressBar::DOWN:
		pivot = Vec2(0.5f, 1);
		break;
	case ProgressBar::LEFT:
		pivot = Vec2(0.f, 0.5f);
		break;
	case ProgressBar::RIGHT:
		pivot = Vec2(1.f, 0.5f);
		break;
	default:
		break;
	}

	originSize = size;
}

ProgressBar::~ProgressBar()
{

}

void ProgressBar::Update()
{
	GameObject::Update();

	ProcProgress();
}

void ProgressBar::ProcProgress()
{
	if (targetPercent == curPercent)
		return;

	float add = targetPercent - curPercent;
	
	if(abs(add) < 0.1f)
		curPercent = targetPercent;
	else
		curPercent += add * Time::deltaTime * Time::timeScale;
	
	switch (fillType)
	{
	case ProgressBar::UP:
		size.bottom = originSize.bottom * (curPercent / 100.f);
		break;
	case ProgressBar::DOWN:
		size.top = originSize.bottom * ((100 - curPercent) / 100.f);
		break;
	case ProgressBar::LEFT:
		size.right = originSize.right * (curPercent / 100.f);
		break;
	case ProgressBar::RIGHT:
		size.left = originSize.right * ((100 - curPercent) / 100.f);
		break;
	default:
		break;
	}
}

void ProgressBar::SetProgress(float _target)
{
	targetPercent = _target;
}

void ProgressBar::SetProgressImmediately(float _target)
{
	targetPercent = _target;
	curPercent = _target;

	switch (fillType)
	{
	case ProgressBar::UP:
		size.bottom = size.bottom * (curPercent / 100.f);
		break;
	case ProgressBar::DOWN:
		size.top = size.bottom * ((100 - curPercent) / 100.f);
		break;
	case ProgressBar::LEFT:
		size.right = size.right * (curPercent / 100.f);
		break;
	case ProgressBar::RIGHT:
		size.left = size.right * ((100 - curPercent) / 100.f);
		break;
	default:
		break;
	}
}
