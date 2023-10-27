#include <assert.h>
#include <stdio.h>

int
_strlen(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
}

int
main(void)
{
	int n;
	char s[] = "Array Two";

	n = _strlen(s);

	assert(n == 9);
}
