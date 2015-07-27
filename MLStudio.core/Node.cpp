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
	node_id = Utility::GetId();
}
const std::map<size_t, InputEndpoint>& Node::GetInputMapping()
{
	return inputs;
}
const std::map<size_t, OutputEndpoint>& Node::GetOutputMapping()
{
	return outputs;
}
void Node::ConnectInToOut(InputEndpoint& inp, OutputEndpoint& out)
{
	inp.SubscribeOutput(out.GetSink());
}

unsigned int Node::GetId()
{
	return node_id;
}

void Node::SetId(unsigned int id)
{
	node_id = id;
}

Node& Node::operator=(const Node& src)
{
	node_id = src.node_id;
	return *this;
}

void Node::ConnectNode(Node& connectTo, size_t thisEP = 0, size_t thatEP = 0)
{
	auto targetEPMap = connectTo.GetInputMapping();

	try{
		InputEndpoint& inp = inputs.at(thisEP);
		try{
			OutputEndpoint& out = outputs.at(thatEP);
			inp.SubscribeOutput(out.GetSink());
		}
		catch (std::out_of_range ex)
		{
			throw new std::exception();
			// throw nice exception
		}
	}
	catch (std::out_of_range ex)
	{
		throw new std::exception();
		// throw nice exception
	}

	


}

Node::~Node()
{

}

