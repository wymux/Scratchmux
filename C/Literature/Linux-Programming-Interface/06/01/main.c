#include <unistd.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>

extern char **environ;
int jmp(int argc);
static jmp_buf env;
static void f2(void);
static void f1(int argc);

static
void f2(void)
{
	longjmp(env, 2);
}

static
void f1(int argc)
{
	if (argc == 1)
		longjmp(env, 1);
	f2();
}

int
jmp(int argc)
{
	switch (setjmp(env)) {
	case 0:
		printf("Calling f1() after initial setjmp()\n");
		f1(argc);
		break;
	case 1:
		printf("We jumped back from f1()\n");
		break;
	case 2:
		printf("We jumped back from f2()\n");
		break;
	}

	exit(EXIT_SUCCESS);
}
int
main(int argc, char *argv[])
{
	pid_t pid, ppid;

	pid = getpid();
	ppid = getppid();

	printf("Process ID: %d\nParent ID:  %d", pid, ppid);

	char **ep;
	char *env;

	for (ep = environ; *ep != NULL; ep++)
		puts(*ep);
	
	if ((env = getenv("MAIL")) == NULL)
		perror("getenv(\"MAIL\")");
	puts(env);

	if (putenv("TEST=FALSE"))
		perror("putenv(\"TEST=FALSE\")");
	if ((env = getenv("TEST")) == NULL)
		perror("getenv(\"TEST\")");
	puts(env);

	
	if (setenv("TEST", "TRUE", 1))
		perror("setenv(\"TEST\")");
	if ((env = getenv("TEST")) == NULL)
		perror("getenv(\"TEST\")");
	puts(env);

	if (unsetenv("TEST"))
		perror("unsetenv(\"TEST\")");
	if ((env = getenv("TEST")) == NULL)
		perror("getenv(\"TEST\")");

	if (clearenv())
		perror("clearenv()");

	jmp(argc);
	
	return 0;
}
