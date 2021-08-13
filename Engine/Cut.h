#pragma once
#include "GameObject.h"
class Cut : public GameObject
{
public:
	Cut(string _path, function<void(void)> _event);
	virtual ~Cut();

	virtual void Update();

	string path;

	function<void(void)> event;
};

