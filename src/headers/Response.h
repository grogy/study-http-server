#ifndef __Response_H_INCLUDED__
#define __Response_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "HtmlFile.h"
using namespace std;

/**
 * Represent response from server to client
 * It's parse only for HTTP in version 1.1
 * @todo In HTTP/2 are headers in binary form
 */
class Response
{
public:
	/**
	 * Inicialize object with file for response to client
	 */
	Response(FileType * html);
	/**
	 * Delete allocated file
	 * File is allocated from other depency
	 */
	~Response();
	/**
	 * Get reseponse in string represent
	 * @return string representation of response
	 */
	string getInString() const;
private:
	/**
	 * File for proces and send in response
	 */
	FileType * file;
};
#endif
