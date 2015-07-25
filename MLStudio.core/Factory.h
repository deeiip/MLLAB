#include "InputEndpoint.h"
#include "OutputEndpoint.h"
#include <atomic>

#pragma once
class Factory
{
public:
	Factory();
	static InputEndpoint ProduceInputEndpoint();
	static OutputEndpoint ProduceOutputEndpoint();
	~Factory();
};

struct Utility
{
	static std::atomic<int> id_marker;
	int GetId()
	{
		++id_marker;
		return id_marker.load();
	}
};

//std::atomic<int> Utility::id_marker = 0;
