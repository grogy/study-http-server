using namespace std;

class HtmlFile
{
public:
	HtmlFile(string str) {
		html = str;
	}
	string getString() {
		return html;
	}
	string getMimeType() {
		return "text/html";
	}
	int getSizeInBytes() {
		return (int)html.size();
	}
private:
	string html;
};
