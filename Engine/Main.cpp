#include "Headers.h"
#include "System.h"

INT WINAPI WinMain(HINSTANCE _hInst, HINSTANCE, LPTSTR, INT)
{
	System sys;

	sys.Init();

	sys.MsgLoop();
	
	sys.Release();
}