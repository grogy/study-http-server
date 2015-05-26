#include "headers/FileType.h"
#include "headers/Response.h"

using namespace std;


Response::Response(FileType * html) {
	file = html;
}


Response::~Response() {
	delete file;
}


string Response::getInString() const {
	stringstream out;
	out << file->getSizeInBytes();
	string size = out.str();
	return "HTTP/1.1 200 OK\n"
		"Cache-Control: private\n"
		"Content-Type: " + file->getMimeType() + "; charset=utf-8\n"
		"X-Powered-By: HTTP-Server-By-Makes\n"
		"Connection: close\n"
		"Content-Length: " + size + "\n"
		"\n" +
		file->getString() + "\n";
}
