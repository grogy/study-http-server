#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FileWriterException {};


class FileWriter {
public:
	FileWriter(string pathToFile) {
		this->pathToFile = pathToFile;
	}
	void write(string text) {
		ofstream myfile(pathToFile);
		if (!myfile.is_open()) {
			throw new FileWriterException();
		}
		myfile << text;
		myfile.close();
	}
	void append(string text) {
		ofstream myfile;
		myfile.open(pathToFile, std::ios_base::app);
		if (!myfile.is_open()) {
			throw new FileWriterException();
		}
		myfile << text;
		myfile.close();
	}
private:
	string pathToFile;
	string content;
};
