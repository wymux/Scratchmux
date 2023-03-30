#include <stdio.h>
#include <stdlib.h>

#define N 5
float balance[N];

void
getlines(void)
{
	int account;
	float amount;
	while (scanf("%d %f", &account, &amount) != EOF) {
		if (account < 0) {
			fprintf(stderr, "Negative account number invalid.\n");
			exit(1);
		}
		balance[account] += amount;
	}
}

void
printsummary(void)
{
	for (int i = 0; i < N; i++) {
		printf("%d %g\n", i, balance[i]);
	}
}

int
main(void)
{
	getlines();
	printsummary();
	return 0;
}
