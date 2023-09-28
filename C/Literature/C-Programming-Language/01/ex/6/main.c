#include <stdio.h>

main()
{
	int c;

	int d = (getchar() != EOF);
	printf("%d", d);
	while (d) {
		d = (getchar() != EOF);
		printf("%d", d);
	}
}
