#include <stdio.h>
#include <unistd.h>

int
getchar(void)
{
	char c;

	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int
main()
{
	static char buf[1000];
	static char *bufp = buf;
	static int n = 0;

	if (n == 0) {
		n = read(0, buf, sizeof(buf));
		bufp = buf;
	}
	return (--n > 0);
}
