#ifndef __FileReader_H_INCLUDED__
#define __FileReader_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

/**
 * This exception signalize problem with read a file
 */
class FileReaderException {};


/**
 * This class reads content from file storage in hard drive
 */
class FileReader {
public:
	/**
	 * Inicialize object
	 * @param path to file
	 */
	FileReader(string pathToFile);
	/**
	 * Get content from file in string
	 * @return string of content
	 */
	string getContentInString() const;
	/**
	 * Get type of file in string
	 * @return type of file
	 */
	string getTypeOfFile() const;
private:
	/**
	 * Content of file in string
	 */
	string content;
	/**
	 * Path to file in hard drive
	 */
	string pathToFile;
};
#endif
