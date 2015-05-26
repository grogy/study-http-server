#include "headers/HtmlFile.h"
#include "headers/Response.h"

using namespace std;


Response::Response(HtmlFile * html) {
	htmlFile = html;
}


Response::~Response() {
	delete htmlFile;
}


string Response::getInString() {
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
