#include <string>

using namespace std;

class FileType
{
public:
	string getString() const {
		return content;
	}
	virtual ~FileType() {}; // only for remove warnings from compilators
	virtual string getMimeType() const = 0;
	int getSizeInBytes() const {
		return (int)content.size();
	}
protected:
	string content;
};
