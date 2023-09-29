#include <stdio.h>

main()
{
	int c, bl, tb, nl;

	c = bl = tb = nl = 0;
	while ((c = getchar()) != EOF) {
		switch(c) {
		case ' ':
			bl++;
			break;
		case '\t':
			tb++;
			break;
		case '\n':
			nl++;
			break;
		}
	}

	printf("\n%d %d %d\n", bl, tb, nl);
		
}
