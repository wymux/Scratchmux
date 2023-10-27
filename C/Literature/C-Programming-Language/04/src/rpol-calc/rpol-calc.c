#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE	100
#define MAXOP	100
#define NUMBER	'0'
#define MAXVAL	100

double _atof(char s[]);
double pop(void);
int getch(void);
int getop(char []);
void push(double);
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;

int
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(_atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop()  - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

int sp = 0;
double val[MAXVAL];

void
push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double
pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error:tack empty\n");
		return 0.00;
	}
}

int
getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int
getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void
ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too man characters\n");
	else
		buf[bufp++] = c;
}

double
_atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}
