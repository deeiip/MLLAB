#include "Endpoint.h"
#include <string>
#include <vector>
#include "BaseTypes.h"
#pragma once

// This shit need to be movable, used with emplace back
class FileTypeEndpoint : Endpoint
{
private:
	std::string correspondingFileName;
	std::string fullPath;
	DataFileFormat format;
	const EndPointType ioType = EndPointType::FileType;
	int id;
	bool mandetory;
public:
	FileTypeEndpoint();
	bool IsFileType();
	bool IsValueType();
	int getId();
	bool IsMandetory();
	void SetFilename(std::string);
	void SetPath(std::string);
	~FileTypeEndpoint();
};

