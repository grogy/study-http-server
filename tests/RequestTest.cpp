#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/Request.cpp"

TEST_CASE("Complet request from browser") {
	string headers =
		"GET http://domain.com/detail/in/url.aspx HTTP/1.1\n"
		"Host: domain.com\n"
		"Connection: keep-alive\n"
		"User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) Chrome/16.0.912.75 Safari/535.7\n"
		"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\n"
		"Referer: http://www.google.com/url?&q=odetocode\n"
		"Accept-Encoding: gzip,deflate,sdch\n"
		"Accept-Language: en-US,en;q=0.8\n"
		"Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.3\n";
	Request * request = new Request(headers);
	REQUIRE(request->getHost() == "domain.com");
	REQUIRE(request->getURL() == "detail/in/url.aspx");
}
