#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main()
{
	int fd = open("tmp.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	char *buf = "1 2 3 4 5 6 7 8 9 10";
	int len = strlen(buf);

	int flags, accessMode;
	flags = fcntl(fd, F_GETFL);
	flags |= O_APPEND;
	if (flags == -1)
		perror("fcntl()");

	if (flags & O_SYNC)
		printf("Synchronized writes\n");
		
	accessMode = flags & O_ACCMODE;
	if (accessMode == O_WRONLY || accessMode == O_RDWR)
		printf("File is writable\n");

	if (!fd)
		perror("open()");

	if (write(fd, buf, len) != len)
		perror("write()");

	int newfd = dup(fd);
	if (close(fd) == -1)
		perror("close()");
	if (close(newfd) == -1)
		perror("close()");
	
	return 0;
}
