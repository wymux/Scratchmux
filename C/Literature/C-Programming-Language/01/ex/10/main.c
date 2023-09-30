#include <stdio.h>

main()
{
	int c;

	while((c = getchar()) != EOF) {
		switch (c) {
		case '\b':
			puts("\\b");
			break;
		case '\t':
			putchar('\\');
			putchar('t');
			break;
		case '\\':
			putchar('\\');
			break;
		default:
			putchar(c);
		}
	}
			
}
