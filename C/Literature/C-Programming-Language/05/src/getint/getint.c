#include <assert.h>
#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int
getint(int *pm)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pm = 0; isdigit(c); c = getch())
		*pm = 10 * *pm + (c - '0');
	*pm *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

char buf[100];
int bufp = 0;

int
getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void
ungetch(int c)
{
	if (bufp >= 100)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int
main(void)
{
	int p;

	p = 0;

	getint(&p);

	assert(p == 100);

	return 0;
	
}
