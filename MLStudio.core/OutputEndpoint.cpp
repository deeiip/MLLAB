#include "stdafx.h"
#include "OutputEndpoint.h"


OutputEndpoint::OutputEndpoint()
{
	fullPath = "abcd/dfhd/dhd";
}

std::string OutputEndpoint::GetSink()
{
	return fullPath;
}

OutputEndpoint::~OutputEndpoint()
{
}
