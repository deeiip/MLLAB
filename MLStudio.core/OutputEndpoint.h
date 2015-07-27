#pragma once
#include "FileTypeEndpoint.h"
class OutputEndpoint :
	private FileTypeEndpoint
{
public:
	OutputEndpoint();
	std::string GetSink();
	~OutputEndpoint();
};

