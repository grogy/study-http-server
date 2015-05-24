all: compile doc
	echo "All is done."


# install actual version of test library
# use this command before you begin development
# library - https://github.com/philsquared/Catch
install-library:
	rm -f catch.hpp
	wget https://raw.githubusercontent.com/philsquared/Catch/master/single_include/catch.hpp


# compile program
compile:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -Werror -O0 -ggdb -o program.o src/source.cpp


# run unit test
# compile is call because I can control all warning
test: clean compile
	g++ -std=c++11 -o test.o tests/FileWriterTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/FileReaderTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/INIReaderTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/HtmlFileTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/ResponseTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/RequestTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/ResponseBuilderTest.cpp && ./test.o
	# this redirect stderr is only for remove warnings from terminal
	g++ -std=c++11 -o test.o tests/ProgramTest.cpp 2> /dev/null && ./test.o


# run program
run: compile
	./program.o examples/configuration.server.ini examples/configuration.map-files.ini


# clean generated files
clean:
	rm -rf *.o
	rm -rf program.o.*


# todo
doc:
	echo "todo"
