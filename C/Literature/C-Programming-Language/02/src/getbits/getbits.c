#include <stdio.h>

unsigned
getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

int
main(void)
{
	unsigned n;
	int m;

	n = 1023;
	m = getbits(n, 9, 10);

	printf("%d\n", m);

	return 0;
}
