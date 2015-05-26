#include "headers/ResponseBuilder.h"

using namespace std;


ResponseBuilder::ResponseBuilder(INIReader * urlConfiguration, Request * request) {
	this->urlConfiguration = urlConfiguration;
	this->request = request;
}


Response * ResponseBuilder::build() const {
	string requireUrl = request->getURL();
	string pathToFile = urlConfiguration->getValue(requireUrl);
	FileReader * reader = new FileReader(pathToFile);
	FileType * file;
	if (reader->getTypeOfFile() == "html") {
		file = new HtmlFile(reader->getContentInString());
	} else if (reader->getTypeOfFile() == "css") {
		file = new CssFile(reader->getContentInString());
	} else {
		throw "Undefined file type";
	}
	Response * response = new Response(file);
	delete reader;
	return response;
}
