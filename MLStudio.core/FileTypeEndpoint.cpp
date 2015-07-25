#include "stdafx.h"
#include "FileTypeEndpoint.h"




FileTypeEndpoint::FileTypeEndpoint() : Endpoint(EndPointType::FileType)
{
}

int FileTypeEndpoint::getId()
{
	return id;
}

bool FileTypeEndpoint::IsFileType()
{
	return true;
}
bool FileTypeEndpoint::IsValueType()
{
	return false;
}

void FileTypeEndpoint::SetFilename(std::string)
{

}

void FileTypeEndpoint::SetPath(std::string)
{

}

FileTypeEndpoint::~FileTypeEndpoint()
{
}
