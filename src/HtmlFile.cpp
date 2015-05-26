#include "FileType.cpp"

using namespace std;

class HtmlFile : public FileType
{
public:
	HtmlFile(string str) {
		content = str;
	}
	~HtmlFile() {} // only for remove warnings from compilators
	string getMimeType() const {
		return "text/html";
	}
};
