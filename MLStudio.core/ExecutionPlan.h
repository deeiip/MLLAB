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
	const Node& At(unsigned int);
	Node& operator[] (size_t);
	size_t Size();
	void ConnectNode(unsigned int, size_t, size_t);




	~ExecutionPlan();
};

