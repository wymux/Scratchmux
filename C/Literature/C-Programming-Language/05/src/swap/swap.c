#include <assert.h>
#include <stdio.h>

void
swap(int *px, int *py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}

int
main(void)
{
	int n, n1;

	n = 10;
	n1 = 100;

	swap(&n, &n1);
	assert(n == 100);
	assert(n1 == 10);

	return 0;
}
