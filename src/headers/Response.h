#ifndef __Response_H_INCLUDED__
#define __Response_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "HtmlFile.h"
using namespace std;

class Response
{
public:
	Response(FileType * html);
	~Response();
	string getInString();
private:
	FileType * file;
};
#endif
