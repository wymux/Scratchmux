#include <stdio.h>

int
binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}

int
main()
{
	int a1[10] = { 2, 3, 4, 5, 6, 7, 10, 15, 17, 19 };
	int n;

	n = binsearch(15, a1, 10);

	printf("%d\n", n);

	return 0;
}
