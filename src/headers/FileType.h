#ifndef __FileType_H_INCLUDED__
#define __FileType_H_INCLUDED__

#include <string>

using namespace std;

class FileType
{
public:
	/**
	 * Get content from file
	 * @return content from file
	 */
	string getString() const;
	/**
	 * This is only for remove warnings from compilators
	 */
	virtual ~FileType() {};
	/**
	 * Get mime type for headers to response
	 * @return mime type
	 */
	virtual string getMimeType() const = 0;
	/**
	 * Get size
	 * @return [description]
	 */
	int getSizeInBytes() const;
protected:
	/**
	 * Content from file in string
	 */
	string content;
};
#endif
