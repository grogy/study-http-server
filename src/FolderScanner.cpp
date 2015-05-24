#include "dirent.h"
#include <string>

using namespace std;

class FolderScannerException {};

class FolderScanner
{
public:
	FolderScanner(string folder) {
		folderPath = folder;
	}
	string getConfigurationString() {
		DIR * dir;
		struct dirent * entity;
		string output = "";
		if ((dir = opendir (folderPath.c_str())) != NULL) {
			while ((entity = readdir (dir)) != NULL) {
				if (isDotDirectory(string(entity->d_name))) {
					continue;
				}
				output += string(entity->d_name)+"="+folderPath+entity->d_name+"\n";
			}
			closedir (dir);
		} else {
			// folder is not open
			throw FolderScannerException();
		}
		return output;
	}
private:
	string folderPath;
	bool isDotDirectory(string name) {
		if (name == "." || name == "..") {
			return true;
		}
		return false;
	}
};
