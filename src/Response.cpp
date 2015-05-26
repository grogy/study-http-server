#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "HtmlFile.cpp"
using namespace std;

class Response
{
public:
	Response(HtmlFile * html) {
		htmlFile = html;
	}
	~Response() {
		delete htmlFile;
	}
	string getInString() {
		stringstream out;
		out << htmlFile->getSizeInBytes();
		string size = out.str();
		return "HTTP/1.1 200 OK\n"
			"Cache-Control: private\n"
			"Content-Type: " + htmlFile->getMimeType() + "; charset=utf-8\n"
			"X-Powered-By: HTTP-Server-By-Makes\n"
			"Connection: close\n"
			"Content-Length: " + size + "\n"
			"\n" +
			htmlFile->getString() + "\n";
	}
private:
	HtmlFile * htmlFile;
};
