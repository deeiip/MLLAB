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




void ExecutionPlan::ResolveDependency(std::vector<Node>& target)
{
	for each (auto item in target)
	{
		if (!item.IsHot())
		{
			// resolve one step down
		}
		else
		{	
			if (!item.executing)
			{
				
				item.Execute();
			}
			else
			{
				while (item.executing)
				{
					//std::this_thread::yield();
				}
				//wait for execution
			}
		}
	}
}

void ExecutionPlan::Execute()
{
	std::stack<Node> PendingStack;
	auto endNodes = this->EndNodes;
	for (size_t i = 0; i < EndNodes.size(); i++)
	{
		auto currentDependency = EndNodes.at(i).GetDependency();
		int dep_size = currentDependency.size();
		if ((EndNodes.size() > 1) && (i - 1 != EndNodes.size()))
		{
			if (dep_size != 0)
			{
#ifdef ALLOW_MULTITHREADING
				std::future<void> result(std::async(&ExecutionPlan::ResolveDependency, this, EndNodes.at(i).GetDependency()));
#else

				
				ResolveDependency(EndNodes.at(i).GetDependency());
				//ResolveDependencyAsync(EndNodes.at(i).GetDependency());
#endif
			}
			else
			{
#ifdef ALLOW_MULTITHREADING
				std::future<void> result(std::async(&ExecutionPlan::ExecuteNode, this, EndNodes.at(i)));
#else
				
				ExecuteNode(EndNodes.at(i));
				//ExecuteNodeAsync(EndNodes.at(i));
#endif
			}
		}
		else
		{
			if (dep_size != 0)
			{
				ResolveDependency(EndNodes.at(i).GetDependency());
			}
			else
			{
				ExecuteNode(EndNodes.at(i));

			}
		}
	}
}

ExecutionPlan::ExecutionPlan()
{
}


ExecutionPlan::~ExecutionPlan()
{
}
