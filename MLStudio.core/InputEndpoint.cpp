#include "stdafx.h"
#include "InputEndpoint.h"


InputEndpoint::InputEndpoint()
{
}

void InputEndpoint::SubscribeOutput(std::string str)
{
	fullPath = str;
}

std::string InputEndpoint::GetSource()
{
	return fullPath;
}

InputEndpoint::~InputEndpoint()
{
}
