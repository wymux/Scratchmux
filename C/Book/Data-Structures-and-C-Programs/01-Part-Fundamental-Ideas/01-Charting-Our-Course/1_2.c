#include <stdlib.h>
#include <stdio.h>

#define MAXACCT 100
#define NAMELEN 4
#define BUFLEN 100

char acctname[MAXACCT][NAMELEN];
char buf[BUFLEN];
float balance[MAXACCT];
int numaccts = 0;

int findacct();
int samename(int n);
void copyname(int n);
void getlines();
void printsummary();
void writename(int n);

void
copyname(int n)
{
	for (int i = 0; i < NAMELEN; i++) {
		acctname[n][i] = buf[i];
	}
}

int
samename(int n)
{
	for (int i = 0; i < NAMELEN; i++) {
		if (acctname[n][i] != buf[i]) {
			return 0;
		}
	}
	return 1;
}
			

int
findacct(void)
{
	int i;
	for (i = 0; i < numaccts; i++) {
		if (samename(i)) {
			return i;
		}
	}

	if (i >= MAXACCT) {
		fprintf(stderr, "Too many accounts.\n");
		abort();
	}

	copyname(numaccts);
	return numaccts++;
}

void
getlines()
{
	int n;
	float amt;
	while (fgets(buf, BUFLEN, stdin)) {
		n = findacct();
		sscanf(&buf[NAMELEN + 1], "%f", &amt);
		balance[n] += amt;
	}
}

void
printsummary(void)
{
	for (int i = 0; i < numaccts; i++) {
		writename(i);
		printf(" %g\n", balance[i]);
	}
}

void
writename(int n)
{
	for (int i = 0; i < NAMELEN; i++) {
		putchar(acctname[n][i]);
	}
}

int
main(void)
{
	getlines();
	printsummary();
	return 0;
}
