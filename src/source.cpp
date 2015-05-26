#include <stdlib.h>
#include <iostream>
#include "Program.cpp"

using namespace std;


bool state = true;


void sig_handler(int signum)
{
	cout << "Program end. Now it send last response for new request." << endl;
	state = false;
}


int main(int argc, char **argv)
{
	signal(SIGINT, sig_handler);

	Program * program = new Program(argc, argv);
	try {
		program->run(cout, &state);
	} catch (ProgramBadArgumentsException & e) {
		cout << e;
	}
	delete program;
	return 0;
}
