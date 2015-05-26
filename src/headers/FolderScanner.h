#ifndef __FolderScanner_H_INCLUDED__
#define __FolderScanner_H_INCLUDED__

#include "dirent.h"
#include <string>

using namespace std;

class FolderScannerException {};

class FolderScanner
{
public:
	FolderScanner(string folder);
	string getConfigurationString();
private:
	string folderPath;
	bool isDotDirectory(string name);
};
#endif
