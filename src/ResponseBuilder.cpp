#include "headers/ResponseBuilder.h"

using namespace std;


ResponseBuilder::ResponseBuilder(INIReader * urlConfiguration, Request * request) {
	this->urlConfiguration = urlConfiguration;
	this->request = request;
}


Response * ResponseBuilder::build() {
	string requireUrl = request->getURL();
	string pathToFile = urlConfiguration->getValue(requireUrl);
	FileReader * reader = new FileReader(pathToFile);
	HtmlFile * file = new HtmlFile(reader->getContentInString());
	Response * response = new Response(file);
	delete reader;
	return response;
}
