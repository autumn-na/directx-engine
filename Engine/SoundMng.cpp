#include "SoundMng.h"



SoundMng::SoundMng()
{
}


SoundMng::~SoundMng()
{
}

void SoundMng::PlayBGM(string _path)
{
	sndPlaySound(_path.c_str(), SND_LOOP | SND_ASYNC);
}

void SoundMng::PlayFX(string _path)
{
	cnt++;

	mciSendString(("open \"" + _path + "\" type waveaudio alias " + _path + to_string(cnt)).c_str(), NULL, NULL, NULL);
	mciSendString(("play \"" + _path + to_string(cnt) + "\" notify").c_str(), NULL, NULL, NULL);
}
