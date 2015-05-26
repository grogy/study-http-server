#ifndef __ResponseBuilder_H_INCLUDED__
#define __ResponseBuilder_H_INCLUDED__

#include "INIReader.h"
#include "Request.h"
#include "Response.h"
#include "FileReader.h"
#include "CssFile.h"
#include "HtmlFile.h"

using namespace std;

/**
 * Join request and configuration and return response
 * This is a factory (request+configuration => response)
 */
class ResponseBuilder
{
public:
	/**
	 * Inicialize factory for create response from request and configuration
	 */
	ResponseBuilder(INIReader * urlConfiguration, Request * request);
	/**
	 * Build response
	 * @return response as object
	 */
	Response * build() const;
private:
	/**
	 * Save URL map configuration
	 */
	INIReader * urlConfiguration;
	/**
	 * Save request from client
	 */
	Request * request;
};
#endif
