#ifndef __HtmlFile_H_INCLUDED__
#define __HtmlFile_H_INCLUDED__

#include "../FileType.cpp"

using namespace std;

class HtmlFile : public FileType
{
public:
	HtmlFile(string str);
	~HtmlFile() {} // only for remove warnings from compilators
	string getMimeType() const;
};
#endif
