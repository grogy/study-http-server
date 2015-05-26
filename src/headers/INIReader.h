#ifndef __INIReader_H_INCLUDED__
#define __INIReader_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class INIReaderException {};


class INIReader {
public:
	INIReader(string configuration);
	string getValue(string key);
private:
	map<string, string> values;
};
#endif
