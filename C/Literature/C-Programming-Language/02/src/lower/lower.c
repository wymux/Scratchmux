#include <stdio.h>

int
_lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

int
main()
{
	
	printf("%d\n", (_lower('A')));

	return 0;
}
