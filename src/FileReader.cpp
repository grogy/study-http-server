#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

class FileReaderException {};


class FileReader {
public:
	FileReader(string pathToFile) {
		this->pathToFile = pathToFile;
		ifstream myfile(pathToFile.c_str());
		if (!myfile.is_open()) {
			throw FileReaderException();
		}
		string line;
		while (getline(myfile, line)) {
			content += line + "\n";
		}
		myfile.close();
	}
	string getContentInString() {
		return content;
	}
	string getTypeOfFile() const {
		char* lastSlash;
		lastSlash = strstr(pathToFile.c_str(), ".");
		return string(lastSlash).substr(1);
	}
private:
	string content;
	string pathToFile;
};
