#pragma once
#include "GameObject.h"
class ProgressBar : public GameObject
{
public:
	enum FillType
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	FillType fillType;

	RECT originSize;

	float curPercent;
	float targetPercent;



	ProgressBar(string _path, FillType _fillType);
	virtual ~ProgressBar();

	virtual void Update();

	void ProcProgress();
	void SetProgress(float _target);
	void SetProgressImmediately(float _target);
};

