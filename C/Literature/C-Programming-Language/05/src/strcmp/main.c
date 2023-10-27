#include <stdio.h>

int
_strcmp(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int
main(void)
{
	char s[] = "Hello";
	char t[] = "Hello";
	int i;

	i = _strcmp(s, t);

	printf("%d\n", i);
	
	return 0;
}
