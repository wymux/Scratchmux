#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main()
{
	char r_char[5];
	
	srand(getpid());
	
	for (int i = 0; i < 5; i++) {
		r_char[i] = (char) (rand() % 128);
	}

	for (int i = 0; i < 5; i++) {
		printf("Random character: %c\n", r_char[i]);
	}
	
	return 0;
}
