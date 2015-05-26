#include <stdlib.h>
#include <iostream>
#include "Program.cpp"

using namespace std;

bool state = true;

void sig_handler(int signum)
{
	printf("END Program - received signal %d\n", signum);
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
