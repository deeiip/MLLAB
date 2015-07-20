#include <string>
#include <vector>
#include <map>
#pragma once

/*
	Loder will be given a ModuleName, Input file Name, Output File Name and
	It'll find it and Run it and will populate contents of the output file
*/
class Loader
{
private:
	bool ready;
	std::string ModuleName;
	std::string ExecPath;
	std::string MetaPath;
	std::map<std::string, std::string> Args;
public:
	Loader();

	bool IsREady()
	{
		return ready;
	}
	void Load()
	{

	}

	void Load(std::string path)
	{

	}

	void Execute()
	{
		if (!ready)
		{
			Load();
		}
	}
	~Loader();
};

