#ifndef __INIReader_H_INCLUDED__
#define __INIReader_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

/**
 * This exception signalize problem with reads configuration from INI string
 */
class INIReaderException {};


/**
 * Read and create object with configuration in INI format
 * Format is `key=value\n`
 */
class INIReader {
public:
	/**
	 * Inicialize object with configuration string
	 * @param configuration configuration string
	 */
	INIReader(string configuration);
	/**
	 * Get value from configuration
	 * @param  key key for value
	 * @return     value from configuration
	 */
	string getValue(string key);
private:
	/**
	 * Map of configuration key => value
	 */
	map<string, string> values;
};
#endif
