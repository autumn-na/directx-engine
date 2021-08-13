#pragma once
#include "Singleton.h"

class DataMng : public Singleton<DataMng>
{
public:
	DataMng();
	virtual ~DataMng();
};

