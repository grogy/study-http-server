#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FileReaderException {};


class FileReader {
public:
	FileReader() = delete;
	FileReader(string pathToFile) {
		ifstream myfile(pathToFile);
		if (!myfile.is_open()) {
			throw new FileReaderException();
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
private:
	string content;
};
