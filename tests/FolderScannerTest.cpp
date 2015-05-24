#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/FolderScanner.cpp"

TEST_CASE("Scan folder") {
	FolderScanner * scanner = new FolderScanner("tests/static/");
	string scannedConfiguration = scanner->getConfigurationString();
	REQUIRE(scannedConfiguration ==
		"file1.html=tests/static/file1.html\n"
		"file2.html=tests/static/file2.html\n"
		"file3.css=tests/static/file3.css\n"
		"file4.js=tests/static/file4.js\n"
		"index.html=tests/static/index.html\n"
	);
}
