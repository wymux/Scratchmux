#include <stdio.h>

int
_atoi(char s[])
{
	int i, n;

	n = 0;
	for ( i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

int
main()
{
	int n;
	char s[] = "4321";

	n = _atoi(s);

	printf("%d", n);
}	
