#include "Endpoint.h"
#include <string>
#include <vector>
#include "BaseTypes.h"
#pragma once

class FileTypeEndpoint : Endpoint
{
private:
	std::string correspondingFileName;
	std::string fullPath;
	DataFileFormat format;
	const EndPointType ioType = EndPointType::FileType;
public:
	FileTypeEndpoint();
	bool IsFileType();
	bool IsValueType();
	~FileTypeEndpoint();
};

