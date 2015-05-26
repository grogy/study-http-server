#include "INIReader.cpp"
#include "Request.cpp"
#include "Response.cpp"
#include "FileReader.cpp"
using namespace std;

class ResponseBuilder
{
public:
	ResponseBuilder(INIReader * urlConfiguration, Request * request) {
		this->urlConfiguration = urlConfiguration;
		this->request = request;
	}
	Response * build() {
		string requireUrl = request->getURL();
		string pathToFile = urlConfiguration->getValue(requireUrl);
		FileReader * reader = new FileReader(pathToFile);
		HtmlFile * file = new HtmlFile(reader->getContentInString());
		Response * response = new Response(file);
		delete reader;
		return response;
	}
private:
	INIReader * urlConfiguration;
	Request * request;
};
