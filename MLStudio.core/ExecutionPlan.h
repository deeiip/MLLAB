#include "config.h"
#include "Node.h"

#include <string>
#include <vector>
#pragma once
namespace MLStudiocore
{

}
class ExecutionPlan
{
	std::vector<Node> StartNodes; // it'll be prepaired
	std::vector<Node> allNodes; // contains all the nodes of the graph
	std::vector<Node> EndNodes;
	void FindStartNodes();
	void FindEndNodes();
public:
	ExecutionPlan();
	void AddNode();
	void LoadFromFile(std::string);
	void SaveToFile(std::string);
	void ExecuteNode(Node&);
	void ExecuteNodeAsync(Node&);
	void Configure();
	void Build();
	void Execute();
	void Run();
	void ResolveDependency(std::vector<Node>&);
	~ExecutionPlan();
};

