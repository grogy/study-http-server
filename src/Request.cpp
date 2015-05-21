#include <iostream>
#include <string>
using namespace std;

class Request
{
public:
	Request(string headersInString) {
		istringstream iss(headersInString);
		for (string line; getline(iss, line);) {
			headers.push_back(line);
		}
	}
	string getHost() {
		return headers[1].substr(6);
	}
	string getURL() {
		string url = headers[0];
		url = url.substr(4); // remove type of Request (GET)
		url = url.substr(0, url.find(" HTTP/1.")); // remove HTTP version
		url = url.substr(getHost().length()+8); // remove host from URL
		return url;
	}
private:
	vector<string> headers;
};
