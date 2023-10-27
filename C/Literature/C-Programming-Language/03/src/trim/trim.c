#include <assert.h>
#include <stdio.h>
#include <string.h>

int
trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; n--)
		if (s[n] != ' '&& s[n] != '\t' && s[n] != '\n')
			break;
	s[n + 1] = '\0';
	return n;
}

int
main(void)
{
	char s[] = "This contains four spaces.";
	int i;

	trim(s);

	return 0;
}
