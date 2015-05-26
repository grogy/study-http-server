#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/FileReader.cpp"


TEST_CASE("No exists file") {
	REQUIRE_THROWS(FileReader * reader = new FileReader("no-exists-file.ini"));
}


TEST_CASE("Exists file") {
	REQUIRE_NOTHROW(FileReader * reader = new FileReader("tests/valid-configuration.ini"));
}


TEST_CASE("Read content from file") {
	FileReader * reader = new FileReader("tests/valid-configuration.ini");
	REQUIRE(reader->getContentInString() ==
		"port=123\n"
		"log=/tmp/web.log\n"
	);
}


TEST_CASE("Get file type from end of name") {
	FileReader * reader = new FileReader("tests/valid-configuration.ini");
	REQUIRE(reader->getTypeOfFile() == "ini");
	FileReader * reader2 = new FileReader("examples/contact.html");
	REQUIRE(reader2->getTypeOfFile() == "html");
}
