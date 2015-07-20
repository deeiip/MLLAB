#include "Node.h"


Node::Node()
{
	ResultReady = false;
}

Node::Node(const Node&)
{

}
Node::Node(Node&&)
{

}
Node& Node::operator = (const Node&)
{

}


size_t Node::GetInputCount()
{
	return this->NodeInputCount;
}
size_t Node::GetOutputCount()
{
	return this->NodeOutputCount;
}
bool Node::IsReady()
{
	return this->ResultReady;
}
std::vector<Node>& Node::GetDependency()
{
	return this->ConnectsFrom;
}
void Node::Execute()
{

}
bool Node::IsExecutable()
{
	for each (auto item in this->ConnectsFrom)
	{
		if(!item.IsReady())
		{
			return false;
		}
	}
	return true;
}
#ifdef ALLOW_MULTITHREADING
bool Node::IsHot()
{

}
#endif
Node::~Node()
{

}