#include <stdio.h>

void
_strcat(char s[], char t[])
{
	int i, j;

	i = j = 0;

	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
		;
}

int
main(void)
{
	char s[] = "Hello";
	char t[] = " World!";

	_strcat(s, t);

	printf("%s", s);

	return 0;
}
