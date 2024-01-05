#define _GNU_SOURCE

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/uio.h>

void _mkstemp();
void _pread(int argc, char *argv[]);
void _pwrite(int argc, char *argv[]);

int
main(int argc, char *argv[])
{
	int fd, fd1, fd2, fd3;
	int flags, accessMode;
	char *buf = "1 2 3 4 5 6 7 8 9 10\n";
	char *ran = "Random Text\n";
	char buffer[] = "Animal Farm";
	off_t off = 8;

	fd = open(argv[1], O_WRONLY);
	if (fd != -1)
		close(fd);
	else
		fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	flags = fcntl(fd, F_GETFL);
	flags |= O_APPEND;
	if (fcntl(fd, F_SETFL, flags) == -1)
		perror("fcntl()");
	
	accessMode = flags & O_ACCMODE;

	off_t orig;

	orig = lseek(fd, 0, SEEK_CUR);
	lseek(fd, 0, SEEK_SET);
	int s = read(fd, buf, strlen(buf));
	lseek(fd, orig, SEEK_SET);

	int num = pread(fd, buffer, sizeof(buffer) - 1, off);
	buffer[num] = 0x00;
	printf("Output: %s\n", buffer);

	num = pwrite(fd, buffer, sizeof(buffer), off);
	buffer[num] = 0x00;
	printf("Output: %s\n", buffer);

	if (truncate(argv[1], 8) == -1)
		perror("trunacte()");
	if (ftruncate(fd, 8) == -1)
		perror("ftruncate()");
	
	if ((fd1 = dup(fd)) == -1)
		perror("dup()");
	if ((dup2(fd1, fd2)) == -1)
		perror("dup2()");
	if ((dup3(fd1, fd3, O_CLOEXEC)) == -1)
		perror("dup3()");

	_pread(argc, argv);
	_pwrite(argc, argv);
	_mkstemp();
	if (accessMode == O_WRONLY || accessMode == O_RDWR)
		printf("File %s is writable\n", argv[1]);
	if (flags == -1)
		perror("fcntl()");
	if (write(fd, buf, strlen(buf)) == -1)
		perror("write()");
	if (remove(argv[1]) == -1)
		perror("remove()");
	if (close(fd) == -1)
		perror("close()");
}

void
_pwrite(int argc, char *argv[])
{
	int fd;
	struct iovec iov[3];
	struct stat myStruct;
	int x;
#define STR_SIZE 100
	char str[STR_SIZE];
	ssize_t numRead, totRequired;

	if (argc != 2 || strcmp(argv[1], "--help") == 0)
		perror("argc != 2");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		perror("open()");
	totRequired = 0;

	iov[0].iov_base = &myStruct;
	iov[0].iov_len = sizeof(struct stat);
	totRequired += iov[0].iov_len;

	iov[1].iov_base = &x;
	iov[1].iov_len = sizeof(x);
	totRequired += iov[1].iov_len;

	iov[2].iov_base = str;
	iov[2].iov_len = sizeof(str);
	totRequired += iov[2].iov_len;

	numRead = writev(fd, iov, 3);
	numRead = pwritev(fd, iov, 3, 8);
	if (numRead == -1)
		perror("readv()");

	if (numRead < totRequired)
		printf("Read fewer bytes than requested\n");
	printf("Total bytes requested: %ld; bytes written: %ld\n",
	       (long) totRequired, (long) numRead);
}

void
_pread(int argc, char *argv[])
{
	int fd;
	struct iovec iov[3];
	struct stat myStruct;
	int x;
#define STR_SIZE 100
	char str[STR_SIZE];
	ssize_t numRead, totRequired;

	if (argc != 2 || strcmp(argv[1], "--help") == 0)
		perror("argc != 2");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		perror("open()");
	totRequired = 0;

	iov[0].iov_base = &myStruct;
	iov[0].iov_len = sizeof(struct stat);
	totRequired += iov[0].iov_len;

	iov[1].iov_base = &x;
	iov[1].iov_len = sizeof(x);
	totRequired += iov[1].iov_len;

	iov[2].iov_base = str;
	iov[2].iov_len = sizeof(str);
	totRequired += iov[2].iov_len;

	numRead = readv(fd, iov, 3);
	numRead = preadv(fd, iov, 3, 8);
	if (numRead == -1)
		perror("readv()");

	if (numRead < totRequired)
		printf("Read fewer bytes than requested\n");
	printf("Total bytes requested: %ld; bytes read: %ld\n",
	       (long) totRequired, (long) numRead);
}

void
_mkstemp()
{
	FILE* f = tmpfile();
	int fd;
	char template[] = "/tmp/somestringXXXX"; 

	fd = mkstemp(template);
	if (fd == -1)
		perror("mkstemp()");

	printf("Generated filename was: %s\n", template);
	unlink(template);
}
