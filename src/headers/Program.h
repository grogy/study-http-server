#ifndef __Program_H_INCLUDED__
#define __Program_H_INCLUDED__

#include <cstring>
#include "FolderScanner.h"
#include "Network.h"

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
	Program(int argc, char **argv);
	~Program();
	void run(ostream & stream, bool * stateOfProgram);
	void printHelp(ostream & stream);
private:
	short state; // todo - replace numbers something clever
	INIReader * configurationServer;
	INIReader * configurationUrlMap;
};
#endif
