#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int
main()
{
	int sockfd;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[BUFFER_SIZE];
	char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
	char *hostname = "example.com";
	int portno = 80;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("Error opening socket");
		exit(1);
	}

	server = gethostbyname(hostname);
	if (server == NULL) {
		fprintf(stderr, "Error, no such host\n");
		exit(1);
	}

	memset((char *)&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
	serv_addr.sin_port = htons(portno);

	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		perror("Error connecting");
		exit(1);
	}

	if (write(sockfd, request, strlen(request)) < 0) {
		perror("Error writing to socket");
		exit(1);
	}

	memset(buffer, 0, BUFFER_SIZE);
	while (read(sockfd, buffer, BUFFER_SIZE - 1) > 0) {
		printf("%s", buffer);
		memset(buffer, 0, BUFFER_SIZE);
	}

	close(sockfd);
	return 0;
}
