#pragma once
#include "FileTypeEndpoint.h"
class InputEndpoint :
	public FileTypeEndpoint
{
public:
	InputEndpoint();
	void SubscribeOutput(int);
	~InputEndpoint();
};

