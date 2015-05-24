#include <cstring>
#include "Network.cpp"
using namespace std;

class ProgramBadArgumentsException {
	friend ostream & operator<<(ostream & stream, const ProgramBadArgumentsException & obj) {
		stream << "HTTP server error. You have to set configuration files." << endl;
		stream << "For more information run program with parameter '--help', please." << endl;
		return stream;
	}
};

class Program
{
public:
	Program(int argc, char **argv) {
		if (argc == 2 && strncmp(argv[1], "--help", 6) == 0) {
			state = 1;
		} else {
			if (argc < 3) {
				throw ProgramBadArgumentsException();
			}
			pathToConfiguration = argv[1];
			pathToConfiguration = argv[2];
			state = 2;
		}
	}
	void run(ostream & stream) {
		Network * network = new Network();
		switch (state) {
			case 1:
				printHelp(stream);
				break;
			case 2:
				network->run("3490");
				break;
			default:
				throw "Invalid state in program.";
		}
	}
	void printHelp(ostream & stream) {
		// todo - here miss larger text
		stream << "This is a help. TODO.." << endl;
	}
private:
	string pathToConfiguration;
	string pathToURLMap;
	short state; // todo - replace numbers something clever
};
