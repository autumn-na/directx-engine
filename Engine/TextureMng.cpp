#include "TextureMng.h"
#include "GraphicMng.h"


TextureMng::TextureMng()
{
}


TextureMng::~TextureMng()
{
}

bool TextureMng::AddTexture(string _path)
{
	TextureData add;
	add.path = _path;

	HRESULT result;
	result = D3DXCreateTextureFromFileEx
	(
		GraphicMng::GetInstance()->d3dDevice9,
		add.path.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		1,
		1,
		NULL,
		&add.imageInfo,
		NULL,
		&add.texture
	);

	if (result == D3D_OK)
	{
		textureData.push_back(add);
		return true;
	}
	else
		return false;
}

Texture TextureMng::LoadTexture(string _path)
{
	for (int i = 0; i < textureData.size(); i++)
	{
		if (textureData[i].path == _path)
		{
			return textureData[i].texture;
		}
	}

	if (AddTexture(_path) == true)
		return textureData[textureData.size() - 1].texture;
	else
		return NULL;
}

ImageInfo TextureMng::LoadImageInfo(string _path)
{
	for (int i = 0; i < textureData.size(); i++)
	{
		if (textureData[i].path == _path)
		{
			return textureData[i].imageInfo;
		}
	}

	if (AddTexture(_path) == true)
		return textureData[textureData.size() - 1].imageInfo;
	else
		return ImageInfo();
}

void TextureMng::ReleaseAll()
{
	for (int i = 0; i < textureData.size(); i++)
	{
		textureData[i].texture->Release();
	}

	textureData.clear();
}
