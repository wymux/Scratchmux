#include <assert.h>
#include <string.h>

void
reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int
main(void)
{
	char s[] = ".setib tac ehT";
	char c[] = "The cat bites.";
	int i;

	reverse(s);

	for (i = 0; i < strlen(s) - 1; i++)
		assert(s[i] == c[i]);
	
	return 0;
}
