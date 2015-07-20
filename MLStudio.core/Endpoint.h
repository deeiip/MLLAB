#include "BaseTypes.h"
#pragma once
class Endpoint
{
private:
	EndPointType __eptype;
public:
	Endpoint(EndPointType);
	virtual EndPointType GetEndPointType();
	virtual bool IsFileType() = 0;
	virtual bool IsValueType() = 0;
	~Endpoint();
};

