#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include <stdio.h>
#include <math.h>
#include  <time.h>

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <functional>

#pragma comment (linker, "/entry:WinMainCRTStartup /subsystem:console")
#pragma comment (lib, "winmm")

using namespace std;

typedef D3DXVECTOR2 Vec2;
typedef D3DXVECTOR3 Vec3;
typedef LPDIRECT3DTEXTURE9 Texture;
typedef D3DXIMAGE_INFO ImageInfo;