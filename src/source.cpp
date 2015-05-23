#include <iostream>
#include "program.cpp"

using namespace std;

int main(int argc, char **argv)
{
	try {
		Program * program = new Program(argc, argv);
		program->run(cout);
	} catch (ProgramBadArgumentsException & e) {
		cout << e;
	}
	return 0;
}
