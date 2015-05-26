#include "headers/INIReader.h"

using namespace std;


INIReader::INIReader(string configuration) {
	istringstream lines(configuration);
	string line;
	while (getline(lines, line)) {
		string key;
		string value;
		bool isSetKey = false;
		istringstream iline(line);
		while (getline(iline, value, '=')) {
			if (!isSetKey) {
				key = value;
				isSetKey = true;
			}
		}
		values.insert(pair<string, string>(key, value));
	}
}


string INIReader::getValue(string key) {
	if (values.find(key) == values.end()) {
		throw INIReaderException();
	}
	return values[key];
}
