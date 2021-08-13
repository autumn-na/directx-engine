#pragma once
#include "Singleton.h"
#include "Headers.h"

struct TextureData
{ 
	string path;
	Texture texture;
	ImageInfo imageInfo;
};

class TextureMng : public Singleton<TextureMng>
{
public:
	vector<TextureData> textureData;



	TextureMng();
	virtual ~TextureMng();

	bool AddTexture(string _path);
	Texture LoadTexture(string _path);
	ImageInfo LoadImageInfo(string _path);

	void ReleaseAll();
};

