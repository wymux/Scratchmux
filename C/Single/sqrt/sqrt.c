#include <stdio.h>

double sqrt(double x)
{
	double y;
	int p, sq, c;

	p = 0;
	do {
		p++;
		sq = (p + 1) * (p + 1);
	}
	while (x > sq);

	y = (double) p;
	c = 0;
	while (c < 10) {
		y = ((x / y + 2) / 2);
		if ((y * y) == x)
			return(y);
		c++;
	}
	return(y);
}

int
main()
{
	double pv, sr;

	printf("Enter positive rational number: ");
	scanf("%lf", &pv);
	if (pv < 0)
		return(0);

	sr = sqrt(pv);
	printf("The sqare root of %.0f is %f\n", pv, sr);

	return(0);
}
