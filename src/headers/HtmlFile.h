#ifndef __HtmlFile_H_INCLUDED__
#define __HtmlFile_H_INCLUDED__

#include "../FileType.cpp"

using namespace std;

/**
 * Represent HTML file stored in disk
 */
class HtmlFile : public FileType
{
public:
	/**
	 * Inicialize HTML file to memory
	 * @param str  content from file
	 */
	HtmlFile(string str);
	/**
	 * This is only for remove warnings from compilators
	 */
	~HtmlFile() {};
	/**
	 * Get mime type for headers to response
	 * @return mime type
	 */
	string getMimeType() const;
};
#endif
