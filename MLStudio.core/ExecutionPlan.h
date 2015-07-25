#include "config.h"
#include "Node.h"
#include <iterator>

#include <string>
#include <vector>
#pragma once

class ExecutionPlan
{
private:
	std::vector<Node> availableNodes;

public:
	unsigned int AddNode(Node&);
	Node& GetNodeById(unsigned int);
	std::vector<Node>::const_iterator Begin();
	std::vector<Node>::const_iterator End();
	Node& At(unsigned int);
	~ExecutionPlan();
};

