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
test: compile
	g++ -o test.o tests/test.cpp
	./test.o


# run program
run: compile
	./program.o


# clean generated files
clean:
	rm -rf *.o
	rm -rf program.o.*


# todo
doc:
	echo "todo"
