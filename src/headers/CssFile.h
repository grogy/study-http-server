#ifndef __CssFile_H_INCLUDED__
#define __CssFile_H_INCLUDED__

#include "../FileType.cpp"

using namespace std;

/**
 * Represent CSS file stored in disk
 */
class CssFile : public FileType
{
public:
	/**
	 * Inicialize CSS file to memory
	 * @param str  content from file
	 */
	CssFile(string str);
	/**
	 * This is only for remove warnings from compilators
	 */
	~CssFile() {};
	/**
	 * Get mime type for headers to response
	 * @return mime type
	 */
	string getMimeType() const;
};
#endif
