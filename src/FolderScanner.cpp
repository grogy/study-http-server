#include "headers/FolderScanner.h"

using namespace std;


FolderScanner::FolderScanner(string folder) {
	folderPath = folder;
}


string FolderScanner::getConfigurationString() const {
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


bool FolderScanner::isDotDirectory(string name) const {
	if (name == "." || name == "..") {
		return true;
	}
	return false;
}
