CXX=g++
CXXFLAGS=-Wall -pedantic -Wno-long-long -O0 -ggdb
LDFLAGS=
DOXYGEN = doxygen
EXECUTABLE=program
SOURCES=src/source.cpp src/Program.cpp src/Network.cpp src/FileReader.cpp src/FileWriter.cpp src/FolderScanner.cpp src/HtmlFile.cpp src/INIReader.cpp src/Request.cpp src/Response.cpp src/ResponseBuilder.cpp


all: $(SOURCES:.cpp=.o) doc
	$(CXX) $(LDFLAGS) $(SOURCES:.cpp=.o) -o $(EXECUTABLE)


clean:
	$(RM) $(SOURCES:.cpp=.o) $(EXECUTABLE)


# run program
run:
	./$(EXECUTABLE) examples/configuration.server.ini examples/configuration.map-files.ini


# install actual version of test library
# use this command before you begin development
# library - https://github.com/philsquared/Catch
install-library:
	rm -f catch.hpp
	wget https://raw.githubusercontent.com/philsquared/Catch/master/single_include/catch.hpp


# run unit test
test: clean-tests
	g++ -std=c++11 -o test.o tests/FileWriterTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/FileReaderTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/FolderScannerTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/INIReaderTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/HtmlFileTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/ResponseTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/RequestTest.cpp && ./test.o
	g++ -std=c++11 -o test.o tests/ResponseBuilderTest.cpp && ./test.o
	# this redirect stderr is only for remove warnings from terminal
	g++ -std=c++11 -o test.o tests/ProgramTest.cpp 2> /dev/null && ./test.o


# clean generated files
clean-test:
	rm -rf *.o
	rm -rf program.o.*


# generate documentation
doc: Doxyfile
	$(DOXYGEN) $<
