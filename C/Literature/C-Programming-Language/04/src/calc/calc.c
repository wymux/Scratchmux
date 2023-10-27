#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000
 
int
_getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
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

int
_atoi(char s[])
{
	double _atof(char s[]);

	return (int) _atof(s);
}

int
main(void)
{
	double sum, _atof(char []);
	char line[MAXLINE];
	int _getline(char line[], int max);

	sum = 0;
	while (_getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum +- _atof(line));
	return 0;
}
