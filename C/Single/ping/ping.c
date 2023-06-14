#include "ping.h"

bool g_running;

int
handle_opt(opt_t opt)
{
	if (opt.err) {
		print_help();
		exit(1);
	}
	if (opt.help) {
		print_help();
		exit(0);
	}
	if (opt.verbose) {
		printf("verbose mode enabled\n");
	}
	if (opt.hostname == NULL) {
		fprintf(stderr, "Error: hostname is required\n");
		exit(1);
	}
	return 0;
}

void
sig_handler(int sig)
{
	g_running = false;
	printf("\n--- %s ping statistics ---\n", "ft_ping");
	return;
}

void
dns_lookup(char *hostname)
{
	struct addrinfo hints, *res;
	struct sockaddr_in *addr;
	char addrstr[INET_ADDRSTRLEN];

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	int err = getaddrinfo(hostname, NULL, &hints, &res);
	if (err != 0) {
		fprintf(stderr, "ping: %s: Name or service not known\n", hostname);
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
		exit(1);
	}

	addr = (struct sockaddr_in *)res->ai_addr;
	inet_ntop(AF_INET, &(addr->sin_addr), addrstr, INET_ADDRSTRLEN);

	printf("PING %s (%s): 56 data bytes\n", hostname, addrstr);
	printf("IPv4 Address: %s\n", addrstr);

	freeaddrinfo(res);
}

int
main(int argc, char **argv)
{
	opt_t opt;
	if (getuid() != 0) {
		printf("Error: You must be root.\n");
		return 1;
	}
	if (argc < 2) {
		printf("Usage: %s <hostname>\n", argv[0]);
		return 1;
	}
	opt = parse_opt(argc, argv);
	handle_opt(opt);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	g_running = true;
	dns_lookup(opt.hostname);

	struct timeval tv;
	gettimeofday(&tv, NULL);
	while (g_running) {
		printf("ping\n");
		sleep(1);
	}

	return 0;
}
