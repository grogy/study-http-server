#ifndef __FileWriter_H_INCLUDED__
#define __FileWriter_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/**
 * This exception signalize problem with write a file
 */
class FileWriterException {};


/**
 * This class writes content from file storage in hard drive
 */
class FileWriter {
public:
	/**
	 * Inicialize object
	 * @param path to file
	 */
	FileWriter(string pathToFile);
	/**
	 * Write text to file
	 * If file no-exist then is file create
	 * If file exists then is file replace
	 * @param text new text for file
	 */
	void write(string text);
	/**
	 * Append text to end of file
	 * @param text new text for file
	 */
	void append(string text);
private:
	/**
	 * Path to file in hard drive
	 */
	string pathToFile;
	/**
	 * Content from file in hard drive
	 */
	string content;
};
#endif
