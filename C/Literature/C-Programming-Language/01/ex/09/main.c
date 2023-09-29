#include <stdio.h>

main()
{
	int c;
	int bl;

	bl = 0;

	while ((c = getchar()) != EOF) {

		if (bl == 1 && (c != ' ')) {
			putchar(' ');
			bl = 0;
		}

		if (c == ' ') {
			bl = 1;
		}
		if (bl != 1) {
			putchar(c);
		}
	}
}
