#ifndef __Program_H_INCLUDED__
#define __Program_H_INCLUDED__

#include <cstring>
#include "FolderScanner.h"
#include "Network.h"

using namespace std;


/**
 * Exception check bad count parameters from terminal
 */
class ProgramBadArgumentsException {
	/**
	 * Overloading output operator for comfortable work with exception
	 */
	friend ostream & operator<<(ostream & stream, const ProgramBadArgumentsException & obj) {
		stream << "HTTP server error. You have to set configuration files." << endl;
		stream << "For more information run program with parameter '--help', please." << endl;
		return stream;
	}
};


/**
 * Base class which run network communication, display help or imformation about errors
 * @todo for this class sometime miss tests
 */
class Program
{
public:
	Program(int argc, char **argv);
	~Program();
	/**
	 * Run program
	 * @param stream         stream for write messages
	 * @param stateOfProgram pointer for check SIGTERM
	 */
	void run(ostream & stream, bool * stateOfProgram) const;
	/**
	 * Print messages from helper
	 * @param stream stream for write help message
	 */
	void printHelp(ostream & stream) const;
private:
	/**
	 * This property save state of program - as state is display help (=1) or run (=2)
	 * @todo - replace numbers something clever
	 */
	short state;
	/**
	 * Hold information about server configuration
	 */
	INIReader * configurationServer;
	/**
	 * Hold information about map URL from virtual memory
	 */
	INIReader * configurationUrlMap;
};
#endif
