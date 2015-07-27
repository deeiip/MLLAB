#include "config.h"
#include "stdafx.h"
#include "ExecutionPlan.h"
#include "FileTypeEndpoint.h"
#include "Factory.h"


unsigned int ExecutionPlan::AddNode(Node& target)
{
	auto id = Utility::GetId();
	target.SetId(id);
	availableNodes.emplace_back(target);
	return id;
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
	NodeMeta nm;
	Node n(nm);
	n.SetId(0);
	return Node(NodeMeta());
}
std::vector<Node>::const_iterator ExecutionPlan::Begin()
{
	return availableNodes.begin();
}
std::vector<Node>::const_iterator ExecutionPlan::End()
{
	return availableNodes.end();
}

size_t ExecutionPlan::Size()
{
	return availableNodes.size();
}

const Node& ExecutionPlan::At(unsigned int idx)
{
	return availableNodes.at(idx);
}

Node& ExecutionPlan::operator[] (size_t idx)
{
	return availableNodes[idx];
}

void ExecutionPlan::ConnectNode(unsigned int toNodeId, size_t thisEP = 0, size_t thatEP = 0)
{
	
	
}

ExecutionPlan::~ExecutionPlan()
{
}
