#ifndef __FileType_CPP_INCLUDED__
#define __FileType_CPP_INCLUDED__
#include "headers/FileType.h"

using namespace std;


string FileType::getString() const {
	return content;
}


int FileType::getSizeInBytes() const {
	return (int)content.size();
}
#endif
