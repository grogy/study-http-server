#include "headers/FileReader.h"

using namespace std;


FileReader::FileReader(string pathToFile) {
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


string FileReader::getContentInString() const {
	return content;
}


string FileReader::getTypeOfFile() const {
	char* lastSlash;
	string dot = ".";
	lastSlash = strstr(const_cast<char*>(pathToFile.c_str()), const_cast<char*>(dot.c_str()));
	return string(lastSlash).substr(1);
}
