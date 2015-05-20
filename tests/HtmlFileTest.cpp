#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/HtmlFile.cpp"

TEST_CASE("Box for HTML data from file") {
	string html = "<p>My text..</p>";
	HtmlFile * htmlFile = new HtmlFile(html);
	REQUIRE(htmlFile->getString() == "<p>My text..</p>");
}
