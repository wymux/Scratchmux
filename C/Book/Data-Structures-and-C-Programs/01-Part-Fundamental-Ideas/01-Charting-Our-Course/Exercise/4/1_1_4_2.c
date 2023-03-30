#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define N 16
int actacct[N];
float balance[N];

int numfind, numseen;

float
randfloat(void)
{
	float rand_float = ((round(((float) rand() / rand()) * 100)) / 100);
	return rand_float;
}

int
randnum(void)
{
	int rand_int = (rand() % 14);
	return rand_int;
}

void
getlines(float amount, int account)
{
	numfind++;
	balance[account] += amount;
	actacct[account] = 1;
	numseen++;
}

void
printsummary(void)
{
	for (int i = 0; i < N; i++) {
		if (balance[i] != 0) {
			printf("%d %g\n", i, balance[i]);
		}
		if (actacct[i] == 1) {
			printf("Active account: %d\n", i);
		}
	}
}

int
main(void)
{
	srand(getpid());
	
	for (int i = 0; i < 50; i++) {
		getlines(randfloat(), randnum());
	}

	printsummary();
	
	return 0;
}
