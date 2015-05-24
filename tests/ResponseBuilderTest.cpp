#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/ResponseBuilder.cpp"

TEST_CASE("Build HTML response", "integrate") {
	string urlConfigurationInString = "index.html=tests/static/index.html\n";
	INIReader * urlConfiguration = new INIReader(urlConfigurationInString);

	string requestHeaders =
		"GET /index.html HTTP/1.1\n"
		"Host: server.com\n";
	Request * request = new Request(requestHeaders);

	HtmlFile * htmlFile = new HtmlFile("tests/static/index.html");
	Response * referenceResponse = new Response(htmlFile);

	ResponseBuilder * builder = new ResponseBuilder(urlConfiguration, request);
	Response * response = builder->build();
	REQUIRE(referenceResponse->getInString() == response->getInString());
}
