#ifndef __FileType_H_INCLUDED__
#define __FileType_H_INCLUDED__

#include <string>

using namespace std;

class FileType
{
public:
	string getString() const;
	virtual ~FileType() {}; // only for remove warnings from compilators
	virtual string getMimeType() const = 0;
	int getSizeInBytes() const;
protected:
	string content;
};
#endif
