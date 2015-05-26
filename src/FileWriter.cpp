#include "headers/FileWriter.h"

using namespace std;


FileWriter::FileWriter(string pathToFile) {
	this->pathToFile = pathToFile;
}


void FileWriter::write(string text) {
	ofstream myfile(pathToFile.c_str());
	if (!myfile.is_open()) {
		throw FileWriterException();
	}
	myfile << text;
	myfile.close();
}


void FileWriter::append(string text) {
	ofstream myfile;
	myfile.open(pathToFile.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::app);
	if (!myfile.is_open()) {
		throw FileWriterException();
	}
	myfile << text;
	myfile.close();
}
