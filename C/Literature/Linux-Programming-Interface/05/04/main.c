#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int
main()
{
	int file_desc = open("dup.txt", O_WRONLY | O_APPEND);
	if (file_desc < 0)
		printf("Error opening file\n");
	int copy_desc = dup(file_desc);
	write(copy_desc, "Outputted to dup.txt", 21);
	write(file_desc, "Outputted to dup.txt as well", 30);
	return 0;
}
