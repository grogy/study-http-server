#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/Response.cpp"

TEST_CASE("Success HTML response") {
	string html = "<h1>Here is a heading of page..</h1>";
	HtmlFile * htmlFile = new HtmlFile(html);
	Response * response = new Response(htmlFile);
	REQUIRE(response->getInString() == "HTTP/1.1 200 OK\n"
		"Cache-Control: private\n"
		"Content-Type: text/html; charset=utf-8\n"
		"X-Powered-By: HTTP-Server-By-Makes\n"
		"Connection: close\n"
		"Content-Length: 36\n"
		"\n"
		"<h1>Here is a heading of page..</h1>\n"
	);
}
