#include "config.h"
#include "stdafx.h"
#include "ExecutionPlan.h"

#include <stack>
#include <vector>


// Wrong logic. Correct it
void ExecutionPlan::FindStartNodes()
{
	for each (auto item in allNodes)
	{
		if (item.GetInputCount() == 0)
		{
			Node target(item);
			StartNodes.push_back(target);
			
		}
	}
}

void ExecutionPlan::FindEndNodes()
{
	for each (auto item in allNodes)
	{
		if (item.GetDependency().size() == 0)
		{
			EndNodes.push_back(item);
		}
	}
}
//
//void ExecutionPlan::Execute()
//{
//	std::vector<Node>& currentPool = StartNodes;
//	size_t startSize = StartNodes.size();
//	
//	for (size_t i = 0; i < StartNodes.size(); i++)
//	{
//		if ((startSize>1) && (i != startSize - 1))
//		{
//			std::future<void> result(std::async(&ExecutionPlan::BuildNode, this, StartNodes.at(i)));
//		}
//	}
//}

void ExecutionPlan::ExecuteNode(Node& target)
{
	target.Execute();
}

#ifdef ALLOW_MULTITHREADING

// concurrent execution function
#else


void ExecutionPlan::ResolveDependency(std::vector<Node>& target)
{
	for each (auto item in target)
	{
		if (item.IsReady())
		{
			// computed node do nothing
		}
		else if (item.IsExecutable())
		{
			item.Execute();
		}
		else
		{
			auto ResolveTarget = item.GetDependency();
			ResolveDependency(ResolveTarget);
			item.Execute();
		}
	}
}


void ExecutionPlan::Execute()
{
	for each (auto item in this->StartNodes)
	{
		if ()
	}
}
#endif


ExecutionPlan::ExecutionPlan()
{
}


ExecutionPlan::~ExecutionPlan()
{
}
