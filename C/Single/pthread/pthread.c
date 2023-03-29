#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg)
{
	int* param;
	param = (int *) arg;
	printf("The parameter passed to the thread is %d\n", *param);
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread;
	int id = 42;

	if (pthread_create(&thread, NULL, thread_function, &id)) {
		fprintf(stderr, "Error creating thread\n");
		exit(-1);
	}

	if (pthread_join(thread, NULL)) {
		fprintf(stderr, "Error joining thread\n");
		exit(-1);
	}

	return 0;
}
