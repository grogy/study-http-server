#ifndef __Request_H_INCLUDED__
#define __Request_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Request
{
public:
	Request(string headersInString);
	string getHost();
	string getURL();
private:
	vector<string> headers;
};
#endif
