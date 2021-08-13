#include "GraphicMng.h"
#include "WindowNS.h"


GraphicMng::GraphicMng()
{
}


GraphicMng::~GraphicMng()
{
}

void GraphicMng::Init()
{
	CreateMainWindow();
	CreateD3D9();
	CreateDevice9();
	CreateD3DXSprite();
	CreateD3DXFont();
}

HRESULT WINAPI WndProc(HWND _hwnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)
{
	switch (_msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(_hwnd, _msg, _wParam, _lParam);
	}
}

void GraphicMng::CreateMainWindow()
{
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = HBRUSH(BLACK_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hInstance = NULL;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = WindowNS::CLASS_NAME;
	wc.lpszMenuName = WindowNS::MENU_NAME;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	RegisterClass(&wc);

	hwnd = CreateWindow
	(
		WindowNS::CLASS_NAME,
		WindowNS::WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		WindowNS::X,
		WindowNS::Y,
		WindowNS::WIDTH,
		WindowNS::HEIGHT,
		NULL,
		NULL,
		wc.hInstance,
		NULL
	);

	RECT newSize;
	SetRect(&newSize, 0, 0, WindowNS::WIDTH, WindowNS::HEIGHT);

	AdjustWindowRect(&newSize, WS_OVERLAPPEDWINDOW, false);
	MoveWindow(hwnd, 0, 0, newSize.right - newSize.left, newSize.bottom - newSize.top, true);

	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);
}

void GraphicMng::CreateD3D9()
{
	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
}

void GraphicMng::CreateDevice9()
{
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferHeight = WindowNS::HEIGHT;
	d3dpp.BackBufferWidth = WindowNS::WIDTH;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = true;

	d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_MIXED_VERTEXPROCESSING, &d3dpp, &d3dDevice9);
}

void GraphicMng::CreateD3DXSprite()
{
	D3DXCreateSprite(d3dDevice9, &d3dxSprite);
}

void GraphicMng::CreateD3DXFont()
{
	D3DXCreateFont(d3dDevice9, 100, 0, FW_BOLD, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &d3dxFont);
}

void GraphicMng::RenderStart()
{
	d3dDevice9->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dDevice9->BeginScene();
}

void GraphicMng::RenderEnd()
{
	d3dDevice9->EndScene();
	d3dDevice9->Present(NULL, NULL, NULL, NULL);
}

void GraphicMng::Release()
{
	if (d3d9 != NULL)
	{
		d3d9->Release();
	}

	if (d3dDevice9 != NULL)
	{
		d3dDevice9->Release();
	}

	if (d3dxSprite != NULL)
	{
		d3dxSprite->Release();
	}

	if (d3dxFont != NULL)
	{
		d3dxFont->Release();
	}
}

Vec2 GraphicMng::GetMousePos()
{
	GetCursorPos(&mouse);

	ScreenToClient(hwnd, &mouse);

	return Vec2(mouse.x, mouse.y);
}
