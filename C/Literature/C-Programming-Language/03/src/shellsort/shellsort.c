#include <assert.h>

void
shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j + gap] = temp;
			}
}

int
main(void)
{
	int a[] = { 1, 13, 8, 99, 83, 28 };
	int c[] = { 1, 8, 13, 28, 83, 99 };
	int i;

	shellsort(a, 6);

	for (i = 0; i < 6; i++)
		assert(a[i] == c[i]);

	return 0;
}
