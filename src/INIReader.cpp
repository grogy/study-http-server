#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class INIReaderException {};


class INIReader {
public:
	INIReader() = delete;
	INIReader(string configuration) {
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
	string getValue(string key) {
		if (values.find(key) == values.end()) {
			throw INIReaderException();
		}
		return values[key];
	}
private:
	map<string, string> values;
};
