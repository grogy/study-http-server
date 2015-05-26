#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/CssFile.cpp"

TEST_CASE("Box for CSS data from file") {
	string css = "#identifier {color: red;}";
	FileType * cssFile = new CssFile(css);
	REQUIRE(cssFile->getString() == "#identifier {color: red;}");
	REQUIRE(cssFile->getMimeType() == "text/css");
	REQUIRE(cssFile->getSizeInBytes() == 25);
}
