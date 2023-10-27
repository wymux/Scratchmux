#include <assert.h>
#include <string.h>
#include <stdio.h>

void
reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void
_itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;

	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int
main(void)
{
	int i;
	int n = 1234;
	char c[4] = "1234";
	char s[4];

	_itoa(n, s);

	for (i = 0; i < 4; i++)
		printf("%d %d\n", s[i], c[i]);
		assert(s[i] == c[i]);
		       
	return 0;
}

