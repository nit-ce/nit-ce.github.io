#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static void f(void);
static void g(void);
static void h(void);

int main(void)
{
	int pid0, pid1;
	pid0 = getpid();
	pid1 = fork();
	if (pid1 == 0) {
		f();
		g();		/* g() should be called after h() */
		return 0;
	}
	h();			/* h() should be called after f() */
	wait(NULL);		/* waiting for the child process to finish */
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS */

static void f(void)
{
	printf("f()\n");
}

static void g(void)
{
	printf("g()\n");
}

static void h(void)
{
	printf("h()\n");
}
