#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int
main()
{
	int fd;
	
	fd = open("startup", O_RDONLY);
	if (fd == -1)
		errExit("open");

	fd = open("myfile", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR, S_IWUSR);
	if (fd == -1)
		errExit("open");

	fd = open("w.log", O_WRONLY | O_CREAT | O_APPEND,
		  S_IRUSR | S_IWUSR);

	if (fd == -1)
		errExit("open");

	return 0;
}
