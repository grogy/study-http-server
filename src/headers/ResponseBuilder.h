#ifndef __ResponseBuilder_H_INCLUDED__
#define __ResponseBuilder_H_INCLUDED__

#include "INIReader.h"
#include "Request.h"
#include "Response.h"
#include "FileReader.h"

using namespace std;

class ResponseBuilder
{
public:
	ResponseBuilder(INIReader * urlConfiguration, Request * request);
	Response * build();
private:
	INIReader * urlConfiguration;
	Request * request;
};
#endif
