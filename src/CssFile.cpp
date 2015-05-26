#include "FileType.cpp"

using namespace std;

class CssFile : public FileType
{
public:
	CssFile(string str) {
		content = str;
	}
	~CssFile() {} // only for remove warnings from compilators
	string getMimeType() const {
		return "text/css";
	}
};
