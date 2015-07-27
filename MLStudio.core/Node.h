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
	const std::map<size_t, InputEndpoint>& GetInputMapping();
	const std::map<size_t, OutputEndpoint>& GetOutputMapping();
	void ConnectInToOut(InputEndpoint&, OutputEndpoint&);
	unsigned int GetId();
	void SetId(unsigned int);
	Node& operator=(const Node&);


	void ConnectNode(Node&, size_t, size_t);
	~Node();
};

