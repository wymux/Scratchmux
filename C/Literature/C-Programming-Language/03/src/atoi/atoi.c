#include <assert.h>
#include <ctype.h>
#include <stdio.h>

int
_atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}

int
main(void)
{
	char s[] = "12345678910";
	int n;

	n = _atoi(s);

	printf("%d\n", n);
	
	assert(n == 12345678910);

	return 0;
}
