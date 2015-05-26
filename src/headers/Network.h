/**
 * In this class I inspired in URL http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html#sendrecv
 */

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

/**
 * Exception check bad get information from address
 */
class NetworkGetAddrInfoException {};

/**
 * Common exception for errors in network work
 */
class NetworkException {};


/**
 * This class work with network - read and send messages in network connection
 * In this class I inspired in URL http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html#sendrecv
 * @todo for this class miss tests
 */
class Network {
public:
	/**
	 * Run network connection and infinity loop
	 * @param port             number of port
	 * @param logWriter        handler for write log information about access to server
	 * @param urlConfiguration handler for map URL in virtual memory
	 * @param state            pointer for check SIGTERM and end infinity loop
	 */
	void run(const char * port, FileWriter * logWriter, INIReader * urlConfiguration, bool * state) const;
private:
	/**
	 * Get sockaddr structure for IPv4 or IPv6
	 */
	void *get_in_addr(struct sockaddr *sa) const;
	/**
	 * Prepare socket for network connection
	 * @param  port number of port
	 * @return      socket description
	 */
	int prepareSocket(const char * port) const;
	/**
	 * Run infinity loop
	 * @param sockfd           socket description
	 * @param logWriter        handler for write log information about access to server
	 * @param urlConfiguration handler for map URL in virtual memory
	 * @param state            pointer for check SIGTERM and end infinity loop
	 */
	void runLoop(int sockfd, FileWriter * logWriter, INIReader * urlConfiguration, bool * state) const;
};
#endif
