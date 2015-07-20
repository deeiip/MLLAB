#include "config.h"
#include <string>
#include <vector>
#include <map>

#pragma once
/*
*/
class Node
{
private:
	std::string ModuleName;
	std::string NodeId;
	size_t NodeInputCount;
	size_t NodeOutputCount;
	std::vector<std::string> NodeInputFiles;
	std::vector<std::string> NodeOutputFiles;
	std::vector<Node> ConnectsFrom;
	std::vector<std::vector<Node> > ConnectsTo;
#ifdef ALLOW_MULTITHREADING
#include <future>
#include <thread>
#include <mutex>

	
#else
	bool ResultReady;
	bool exec_able;
#endif
	
public:

#ifdef ALLOW_MULTITHREADING
	bool executing;

	bool IsHot();
#endif
	Node();
	Node(const Node&);
	Node(Node&&);
	Node& operator = (const Node&);


	size_t GetInputCount();
	size_t GetOutputCount();
	bool IsReady();
	std::vector<Node>& GetDependency();
	void Execute();
	bool IsExecutable();
	~Node();
};

