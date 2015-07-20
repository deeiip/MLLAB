#include "stdafx.h"
#include "Endpoint.h"


Endpoint::Endpoint(EndPointType typ)
{
	__eptype = typ;
}

EndPointType Endpoint::GetEndPointType()
{
	return __eptype;
}

Endpoint::~Endpoint()
{
}
