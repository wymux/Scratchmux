#include <assert.h>
#include <stdio.h>
#include <string.h>

void
_strcopy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}

int
main(void)
{
	char s[] = "Hello";
	char t[] = " World";
	char _s[] = "Hello World!";
	

	_strcopy(s, t);
        assert(strcmp(_s, s));

	return 0;
}
