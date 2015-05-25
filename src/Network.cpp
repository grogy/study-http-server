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
#include "ResponseBuilder.cpp"

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
	void run(const char * port, FileWriter * logWriter, INIReader * urlConfiguration)
	{
		int sockfd = prepareSocket(port);
		runLoop(sockfd, logWriter, urlConfiguration);
	}
private:
	/**
	 * Get sockaddr for IPv4 or IPv6
	 */
	void *get_in_addr(struct sockaddr *sa) {
		if (sa->sa_family == AF_INET) {
			return &(((struct sockaddr_in*)sa)->sin_addr);
		}
		return &(((struct sockaddr_in6*)sa)->sin6_addr);
	}
	int prepareSocket(const char * port) {
		int sockfd;  // listen on sock_fd
		struct addrinfo hints, *servinfo, *p;
		int yes=1;
		int rv;

		memset(&hints, 0, sizeof hints);
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_flags = AI_PASSIVE; // use my IP

		if ((rv = getaddrinfo(NULL, port, &hints, &servinfo)) != 0) {
			fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
			throw NetworkGetAddrInfoException();
		}

		// loop through all the results and bind to the first we can
		for(p = servinfo; p != NULL; p = p->ai_next) {
			if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
				perror("server: socket");
				continue;
			}

			if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
				perror("setsockopt");
				exit(1);
			}

			if (::bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
				close(sockfd);
				perror("server: bind");
				continue;
			}

			break;
		}

		if (p == NULL)  {
			fprintf(stderr, "server: failed to bind\n");
			throw NetworkException();
		}

		freeaddrinfo(servinfo); // all done with this structure

		if (listen(sockfd, BACKLOG) == -1) {
			perror("listen");
			exit(1);
		}

		printf("server: waiting for connections...\n");

		return sockfd;
	}
	void runLoop(int sockfd, FileWriter * logWriter, INIReader * urlConfiguration) {
		while (true) {
			int new_fd; //new connection on new_fd
			struct sockaddr_storage their_addr; // connector's address information
			socklen_t sin_size = sizeof their_addr;
			char s[INET6_ADDRSTRLEN];

			new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
			if (new_fd == -1) {
				perror("accept");
				continue;
			}

			inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof s);
			printf("server: got connection from %s\n", s);

			char buf[MAXDATASIZE];
			int numbytes = 0;
			if ((numbytes = recv(new_fd, buf, MAXDATASIZE-1, 0)) == -1) {
				perror("recv");
				continue;
			}
			buf[numbytes] = '\0';

			if (!fork()) { // this is the child process
				close(sockfd); // child doesn't need the listener
				std::string headers(buf);
				Request * request = new Request(headers);
				ResponseBuilder * builder = new ResponseBuilder(urlConfiguration, request);
				Response * response = builder->build();
				std::string mystring = response->getInString();
				if (send(new_fd, mystring.c_str(), mystring.length(), 0) == -1) {
					perror("send");
				}
				logWriter->append("[client " + string(s) + "] access to page: " + request->getURL() + "\n");
				close(new_fd);
				exit(0);
			}
			close(new_fd);  // parent doesn't need this
		}
	}
};
