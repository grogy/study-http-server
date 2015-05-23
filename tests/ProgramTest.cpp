#define CATCH_CONFIG_MAIN
#include <cstring>
#include "../catch.hpp"
#include "../src/Program.cpp"


TEST_CASE("Input incorrect count parameters") {
	char * arr[1] = {
		"program.o"
	};
	REQUIRE_THROWS(Program * program = new Program(1, arr));

	char * arr2[2] = {
		"program.o",
		"/path/to/file.ini"
	};
	REQUIRE_THROWS(Program * program = new Program(2, arr2));
}


TEST_CASE("Input correct count parameters") {
	char * arr[3] = {
		"program.o",
		"/path/to/file.ini",
		"/path/to/file2.ini"
	};
	REQUIRE_NOTHROW(Program * program = new Program(3, arr));
}


TEST_CASE("Display help") {
	char * arr[3] = {
		"program.o",
		"--help"
	};
	REQUIRE_NOTHROW(Program * program = new Program(2, arr));
	Program * program = new Program(2, arr);
	stringstream out;
	program->run(out);
	REQUIRE(out.str().substr(0, 14) == "This is a help");
}


TEST_CASE("Display error message from exception") {
	ProgramBadArgumentsException ex = ProgramBadArgumentsException();
	stringstream out;
	out << ex;
	REQUIRE(out.str().substr(0, 17) == "HTTP server error");
}
