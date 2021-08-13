#pragma once
#include "Singleton.h"
#include "Headers.h"

class GraphicMng : public Singleton<GraphicMng>
{
public:
	GraphicMng();
	virtual ~GraphicMng();

	WNDCLASS wc;
	HWND hwnd;

	LPDIRECT3D9 d3d9;
	LPDIRECT3DDEVICE9 d3dDevice9;
	LPD3DXSPRITE d3dxSprite;
	LPD3DXFONT d3dxFont;

	POINT mouse;



	void Init();
	void CreateMainWindow();
	void CreateD3D9();
	void CreateDevice9();
	void CreateD3DXSprite();
	void CreateD3DXFont();

	void RenderStart();
	void RenderEnd();

	void Release();

	Vec2 GetMousePos();
};

