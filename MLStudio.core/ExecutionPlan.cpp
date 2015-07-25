#include "config.h"
#include "stdafx.h"
#include "ExecutionPlan.h"
#include "FileTypeEndpoint.h"


unsigned int ExecutionPlan::AddNode(Node&)
{
	return 1234;
}
Node& ExecutionPlan::GetNodeById(unsigned int id)
{
	for (size_t i = 0; i < availableNodes.size(); i++)
	{
		if (availableNodes.at(i).GetId() == id)
		{
			return availableNodes.at(i);
		}
	}
}
std::vector<Node>::const_iterator ExecutionPlan::Begin()
{
	return availableNodes.begin();
}
std::vector<Node>::const_iterator ExecutionPlan::End()
{
	return availableNodes.end();
}


ExecutionPlan::~ExecutionPlan()
{
}
