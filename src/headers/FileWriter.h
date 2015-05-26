#ifndef __FileWriter_H_INCLUDED__
#define __FileWriter_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FileWriterException {};


class FileWriter {
public:
	FileWriter(string pathToFile);
	void write(string text);
	void append(string text);
private:
	string pathToFile;
	string content;
};
#endif
