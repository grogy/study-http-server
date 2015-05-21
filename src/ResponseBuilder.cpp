#include "INIReader.cpp"
#include "Request.cpp"
#include "Response.cpp"
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
		HtmlFile * file = new HtmlFile(pathToFile);
		Response * response = new Response(file);
		return response;
	}
private:
	INIReader * urlConfiguration;
	Request * request;
};
