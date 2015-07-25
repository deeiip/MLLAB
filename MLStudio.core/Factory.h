#include "InputEndpoint.h"
#include "OutputEndpoint.h"
#pragma once
class Factory
{
public:
	Factory();
	static InputEndpoint ProduceInputEndpoint();
	static OutputEndpoint ProduceOutputEndpoint();
	~Factory();
};

