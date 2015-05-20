#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class INIReaderException {};


class INIReader {
public:
	INIReader() = delete;
	INIReader(string pathToConfigurationFile) {
		ifstream myfile(pathToConfigurationFile);
		if (!myfile.is_open()) {
			throw new INIReaderException();
		}
		string line;
		while (getline(myfile, line)) {
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
		myfile.close();
	}
	string getValue(string key) {
		if (values.find(key) == values.end()) {
			throw new INIReaderException();
		}
		return values[key];
	}
private:
	map<string, string> values;
};
