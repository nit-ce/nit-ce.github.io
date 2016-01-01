#include <stdio.h>
#include <stdlib.h>

static void proc1(void);
static void proc2(void);

int main(void)
{
	int pid1, pid2;
	/* the first process */
	pid1 = fork();
	if (pid1 == 0) {
		proc1();
		return 0;
	}
	/* the second process */
	pid2 = fork();
	if (pid2 == 0) {
		proc2();
		return 0;
	}
	/* waiting until both children terminate */
	wait(NULL);
	wait(NULL);
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS */

static void proc1(void)
{
	while (1) {
		printf("proc1\n");
		sleep(1);
	}
}

static void proc2(void)
{
	while (1) {
		printf("proc2\n");
		sleep(1);
	}
}
