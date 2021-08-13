#pragma once
#include "Singleton.h"
#include "Headers.h"

class SoundMng : public Singleton<SoundMng>
{
public:
	size_t cnt = 0;


	SoundMng();
	virtual ~SoundMng();

	void PlayBGM(string _path);
	void PlayFX(string _path);
};

