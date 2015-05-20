#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/INIReader.cpp"


TEST_CASE("No exists configuration file") {
	REQUIRE_THROWS(INIReader * config = new INIReader("no-exists-file.ini"));
}


TEST_CASE("Exists configuration file") {
	REQUIRE_NOTHROW(INIReader * config = new INIReader("tests/valid-configuration.ini"));
}


TEST_CASE("Read lines from configuration") {
	INIReader * config = new INIReader("tests/valid-configuration.ini");
	REQUIRE(config->getValue("port") == "123");
	REQUIRE(config->getValue("log") == "/tmp/web.log");
	REQUIRE_THROWS(config->getValue("not-exists-key"));
}
