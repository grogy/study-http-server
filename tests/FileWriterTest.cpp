#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/FileReader.cpp"
#include "../src/FileWriter.cpp"


TEST_CASE("Write to no exists file") {
	// all files with begin "program.o" are deleted in start tests
	FileWriter * writer = new FileWriter("program.o.no-exists-file.ini");
	writer->write("This is a file");

	FileReader * reader = new FileReader("program.o.no-exists-file.ini");
	REQUIRE(reader->getContentInString() == "This is a file\n");
}


TEST_CASE("Append to no exists file") {
	// all files with begin "program.o" are deleted in start tests
	FileWriter * writer = new FileWriter("program.o.no-exists-file2.ini");
	writer->append("This is first line\n");
	writer->append("This is second line\n");

	FileReader * reader = new FileReader("program.o.no-exists-file2.ini");
	REQUIRE(reader->getContentInString() ==
		"This is first line\n"
		"This is second line\n"
	);
}
