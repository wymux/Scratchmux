#include <stdio.h>

#define IS_UPPER(N) ((N) >= 'A' && (N) <= 'Z')
#define IS_LOWER(N) ((N) >= 'a' && (N) <= 'z')
#define IS_ALPHA(N) (IS_LOWER(N) || IS_UPPER(N))
#define MAXLEN  17
#define OUT 0
#define IN  1

int main(void)
{
	int c = EOF,
		wbuf[MAXLEN],
		wlen = 0;
	int state = OUT,
		x = 0, /* horizontal histogram */
		y = 0; /* vertical histogram */

	for (int i = 0; i <= MAXLEN; i++)
		wbuf[i] = 0;

	while((c = getchar()) != EOF) {
		if (IS_ALPHA(c) && wlen < MAXLEN) {
			state = IN;
			++wlen;
		} else if (wlen > 0 && wlen < MAXLEN) {
			state = OUT;
			++wbuf[wlen];
			wlen = 0;
		}
	}
	++wbuf[wlen];

	for (int i = 1; i < MAXLEN; i++) {
		if (wbuf[i] && i > x)
			x = i;
		if (wbuf[i] > y)
			y = wbuf[i];
	}

	puts("\nHORIZONTAL HISTOGRAM");
	for (int i = 1; i <= x; i++) {
		printf("%2d | ", i);
		for (int j = 0; j < wbuf[i]; j++)
			printf("* ");
  
		putchar('\n');
	}

	puts("\nVERTICAL HISTOGRAM");
	for (int i = y; i > 0; i--) {
		printf("%2d |", i);
		for(int j = 1; j <= x; j++) {
			if (wbuf[j] < i)
				printf("      ");
			else
				printf(" *    ");
		}
		putchar('\n');
	}
	printf("   +--");
	for (int i = 1; i < x; i++)
		printf("------");
	putchar('\n');

	for (int i = 1; i <= x; i++)
		printf("%6d", i);
	putchar('\n');

	return 0;
}
