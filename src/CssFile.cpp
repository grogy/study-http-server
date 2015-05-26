#include "headers/CssFile.h"

using namespace std;


CssFile::CssFile(string str) {
	content = str;
}


string CssFile::getMimeType() const {
	return "text/css";
}
