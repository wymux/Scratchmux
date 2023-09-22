#include <stdio.h>

void
main()
{
	float fahr, celcius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celcius = lower;

	printf("|Cel|Fah|\n");
	while (celcius <= upper) {
		fahr = (1.8 * celcius) + 32;
		printf("%3.0f %6.1f\n", celcius, fahr);
		celcius = celcius + step;
	}

}
