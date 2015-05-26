#ifndef __CssFile_H_INCLUDED__
#define __CssFile_H_INCLUDED__

#include "../FileType.cpp"

using namespace std;

class CssFile : public FileType
{
public:
	CssFile(string str);
	~CssFile() {}; // only for remove warnings from compilators
	string getMimeType() const;
};
#endif
