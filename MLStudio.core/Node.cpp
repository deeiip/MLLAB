#include "stdafx.h"
#include "Node.h"
#include "Factory.h"



Node::Node(NodeMeta) : 
inputEndCount(3), 
outEndCount(4)
{
	for (size_t i = 0; i < inputEndCount; i++)
	{
		inputs.insert(std::make_pair(i, Factory::ProduceInputEndpoint()));
	}
	for (size_t i = 0; i < outEndCount; i++)
	{
		outputs.insert(std::make_pair(i, Factory::ProduceOutputEndpoint()));
	}
}
std::map<size_t, InputEndpoint>& Node::GetInputMapping()
{
	return this->inputs;
}
std::map<size_t, OutputEndpoint>& Node::GetOutputMapping()
{
	return this->outputs;
}
void Node::ConnectInToOut(InputEndpoint& inp, OutputEndpoint& out)
{
	inp.SubscribeOutput(out.getId());
}

unsigned int Node::GetId()
{
	return 1234;
}

unsigned int Node::SetId(unsigned int)
{
	return 1234;
}

Node::~Node()
{

}

