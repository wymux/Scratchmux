#include <gnu/libc-version.h>

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main()
{
	pid_t pid;

	pid = getpid();
	printf("PID: %ld\n", (long) pid);

	char c[100];
	
	const char *path = "1.txt";
	const char *v = gnu_get_libc_version();
	printf("%s\n", v);

	int fd = open("1.txt", "r", "777");
	if (fd == -1) {
		perror("open()");
		exit(EXIT_FAILURE);
	}

	ssize_t cnt = read(fd, c, 10);
	if (cnt == -1) {
		if (errno == EINTR)
			fprintf(stderr, "read interrupted by signal: %s\n", strerror(errno));
		else {
			c[cnt] = '\0';
			printf("\n%d: %s\n", cnt, c);
		}
	}
	
	return 0;
}
