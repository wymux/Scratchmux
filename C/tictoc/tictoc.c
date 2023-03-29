#include <stdio.h>

int
main (void)
{
	int output = 0;
	int a = 0;
	int b = 0;
	for (int i = 0; i < 16; i++) {
		a = ((i >> 2) & 0x03);
		b = (i & 0x03);
		int result = ((b + (b * b + (4 * a)) / 2) / 2);
		int resulta = (result & 0x01);
		int resultb = ((result >> 1) & 0x01);
		int resultc = ((result >> 2) & 0x01);
		printf("%d:\t | %d | %d\n", i, resultc, resultb, resulta);
	}

	return 0;
}
