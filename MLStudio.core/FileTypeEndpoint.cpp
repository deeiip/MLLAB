#include "stdafx.h"
#include "FileTypeEndpoint.h"




FileTypeEndpoint::FileTypeEndpoint() : Endpoint(EndPointType::FileType)
{
}


bool FileTypeEndpoint::IsFileType()
{
	return true;
}
bool FileTypeEndpoint::IsValueType()
{
	return false;
}

FileTypeEndpoint::~FileTypeEndpoint()
{
}
