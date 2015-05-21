#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/INIReader.cpp"
#include "../src/FileReader.cpp"


TEST_CASE("Read lines from configuration") {
	string configuration = "key1=321\n"
		"key2=abcd\n";
	INIReader * config = new INIReader(configuration);
	REQUIRE(config->getValue("key1") == "321");
	REQUIRE(config->getValue("key2") == "abcd");
	REQUIRE_THROWS(config->getValue("not-exists-key"));
}


TEST_CASE("Read lines from configuration file", "integration") {
	FileReader * reader = new FileReader("tests/valid-configuration.ini");
	INIReader * config = new INIReader(reader->getContentInString());
	REQUIRE(config->getValue("port") == "123");
	REQUIRE(config->getValue("log") == "/tmp/web.log");
}
