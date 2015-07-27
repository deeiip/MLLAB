#pragma once
#include "FileTypeEndpoint.h"
class InputEndpoint :
	private FileTypeEndpoint
{
public:
	InputEndpoint();
	void SubscribeOutput(std::string);
	std::string GetSource();
	~InputEndpoint();
};

