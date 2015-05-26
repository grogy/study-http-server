#ifndef __FolderScanner_H_INCLUDED__
#define __FolderScanner_H_INCLUDED__

#include "dirent.h"
#include <string>

using namespace std;

/**
 * This exception signalize problem with scan files in folder
 */
class FolderScannerException {};

/**
 * Scan files in folder and create configuration string for virtual map URL
 * @todo create recursive read in fodlers and subfolders
 */
class FolderScanner
{
public:
	/**
	 * Inicializace object with path to folder
	 * @param folder path to folder
	 */
	FolderScanner(string folder);
	/**
	 * Get configuration in string represent
	 * This string is optimalizace for INIReader
	 * @return configuration in string for object INIReader
	 */
	string getConfigurationString() const;
private:
	/**
	 * Path to folder
	 */
	string folderPath;
	/**
	 * Check if is folder this (.) or parent (..)
	 */
	bool isDotDirectory(string name) const;
};
#endif
