#include "headers/HtmlFile.h"

using namespace std;


HtmlFile::HtmlFile(string str) {
	content = str;
}


string HtmlFile::getMimeType() const {
	return "text/html";
}
