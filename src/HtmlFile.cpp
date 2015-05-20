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
private:
	string html;
};
