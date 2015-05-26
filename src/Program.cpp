#include <cstring>
#include "FolderScanner.cpp"
#include "FileWriter.cpp"
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
			FileReader * file1 = new FileReader(argv[1]);
			configurationServer = new INIReader(file1->getContentInString());
			FileReader * file2 = new FileReader(argv[2]);
			configurationUrlMap = new INIReader(file2->getContentInString());
			state = 2;
			delete file1;
			delete file2;
		}
	}
	~Program() {
		if (state == 2) {
			delete configurationServer;
			delete configurationUrlMap;
		}
	}
	void run(ostream & stream, bool * stateOfProgram) {
		Network * network = new Network();
		string pathToLogFile;
		FileWriter * logWriter;
		string port;
		INIReader * urlConfiguration;
		FolderScanner * scanner;
		switch (state) {
			case 1:
				printHelp(stream);
				break;
			case 2:
				scanner = new FolderScanner(configurationServer->getValue("root"));
				urlConfiguration = new INIReader(scanner->getConfigurationString());
				pathToLogFile = configurationServer->getValue("log");
				logWriter = new FileWriter(pathToLogFile);
				port = configurationServer->getValue("port");
				network->run(port.c_str(), logWriter, urlConfiguration, stateOfProgram);
				break;
			default:
				throw "Invalid state in program.";
		}
		delete network;
	}
	void printHelp(ostream & stream) {
		// todo - here miss larger text
		stream << "This is a help. TODO.." << endl;
	}
private:
	short state; // todo - replace numbers something clever
	INIReader * configurationServer;
	INIReader * configurationUrlMap;
};
