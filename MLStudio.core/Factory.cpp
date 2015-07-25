#include "stdafx.h"
#include "Factory.h"


Factory::Factory()
{
}

InputEndpoint Factory::ProduceInputEndpoint()
{
	InputEndpoint ret;
	return ret;
}

OutputEndpoint Factory::ProduceOutputEndpoint()
{
	OutputEndpoint ret;
	ret.SetPath("some/path");
	ret.SetFilename("some_UNIQUE_name");
	return ret;
}

Factory::~Factory()
{
}
