#ifndef __ResponseBuilder_H_INCLUDED__
#define __ResponseBuilder_H_INCLUDED__

#include "INIReader.h"
#include "Request.h"
#include "Response.h"
#include "FileReader.h"
#include "CssFile.h"
#include "HtmlFile.h"

using namespace std;

class ResponseBuilder
{
public:
	ResponseBuilder(INIReader * urlConfiguration, Request * request);
	Response * build() const;
private:
	INIReader * urlConfiguration;
	Request * request;
};
#endif
