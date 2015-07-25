#include "config.h"
#include "Endpoint.h"
#include "NodeMeta.h"
#include "InputEndpoint.h"
#include "OutputEndpoint.h"
#include <string>
#include <vector>
#include <map>

#pragma once
/*
*/
class Node
{
private:
	const size_t inputEndCount;
	const size_t outEndCount;

	std::map<size_t, InputEndpoint> inputs;
	std::map<size_t, OutputEndpoint> outputs;

	unsigned int node_id;

public:
	Node(NodeMeta);
	std::map<size_t, InputEndpoint>& GetInputMapping();
	std::map<size_t, OutputEndpoint>& GetOutputMapping();
	void ConnectInToOut(InputEndpoint&, OutputEndpoint&);
	~Node();
};

