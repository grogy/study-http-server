#ifndef __FileReader_H_INCLUDED__
#define __FileReader_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

class FileReaderException {};


class FileReader {
public:
	FileReader(string pathToFile);
	string getContentInString();
	string getTypeOfFile() const;
private:
	string content;
	string pathToFile;
};
#endif
