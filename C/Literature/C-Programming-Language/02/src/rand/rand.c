#include <stdio.h>

unsigned long int next = 1;

int
_rand(void)
{
	next = next * 1103515246 + 12345;
	return (unsigned int)(next/65536) % 32768;
}

void
_srand(unsigned int seed)
{
	next = seed;
}

int
main(void)
{
	int n, m, o;

	n = _rand();

	_srand(10);

	m = _rand();
	o = _rand();

	printf("%d %d %d\n", n, m, o);

	return 0;
}
