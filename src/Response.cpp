#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Response
{
public:
	Response(HtmlFile * html) {
		htmlFile = html;
	}
	string getInString() {
		return "HTTP/1.1 200 OK\n"
			"Cache-Control: private\n"
			"Content-Type: " + htmlFile->getMimeType() + "; charset=utf-8\n"
			"X-Powered-By: HTTP-Server-By-Makes\n"
			"Connection: close\n"
			"Content-Length: " + to_string(htmlFile->getSizeInBytes()) + "\n"
			"\n" +
			htmlFile->getString() + "\n";
	}
private:
	HtmlFile * htmlFile;
};
