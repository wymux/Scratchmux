#include <stdio.h>
#include <stdlib.h>

static void
mstrcat(char *s, char *t)
{
	char p_a[500];
	char *p = p_a;
	
	while (*s != '\0') {
		*p = *s;
		s++;
		p++;
	}
	
	while (*t != '\0') {
		*p = *t;
		p++;
		t++;
	}

	printf("%s\n", p_a);
}

int
main()
{
	char *a = "Hello";
	char *b = " World";
	mstrcat(a, b);
	return 0;
}
