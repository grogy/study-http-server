#ifndef __Network_H_INCLUDED__
#define __Network_H_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#include <map>
#include <sstream>
#include "ResponseBuilder.h"
#include "FileWriter.h"

#define BACKLOG 10     // how many pending connections queue will hold
#define MAXDATASIZE 1000 // Makes

class NetworkGetAddrInfoException {};

class NetworkException {};


/**
 * In this class I inspired in URL http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html#sendrecv
 * @todo for this class miss tests
 */
class Network {
public:
	void run(const char * port, FileWriter * logWriter, INIReader * urlConfiguration, bool * state) const;
private:
	/**
	 * Get sockaddr for IPv4 or IPv6
	 */
	void *get_in_addr(struct sockaddr *sa) const;
	int prepareSocket(const char * port) const;
	void runLoop(int sockfd, FileWriter * logWriter, INIReader * urlConfiguration, bool * state) const;
};
#endif
