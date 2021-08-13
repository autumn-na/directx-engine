#pragma once
class System
{
public:
	System();
	virtual ~System();

	void Init();
	void MsgLoop();
	void MainLoop();
	void Release();
};

