#ifndef __Request_H_INCLUDED__
#define __Request_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/**
 * Represent and process request from client
 * It's parse only request in HTTP in version 1.1
 * @todo In HTTP/2 are headers in binary form
 */
class Request
{
public:
	/**
	 * Inicialize object with headers
	 * @param headersInString headers in string
	 */
	Request(string headersInString);
	/**
	 * Get host
	 * @return host
	 */
	string getHost() const;
	/**
	 * Get access URL
	 * @return URL from request
	 */
	string getURL() const;
private:
	/**
	 * Save headers
	 */
	vector<string> headers;
};
#endif
