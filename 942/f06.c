#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void proc1(void);
static void proc2(void);

static void *thread1(void *v)
{
	return NULL;
}

static void *thread2(void *v)
{
	return NULL;
}

int main(void)
{
	pthread_t t1, t2;
	int n;
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	while (scanf("%d", &n) == 1) {
		if (n == 1)
			proc1();
		if (n == 2)
			proc2();
	}
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS */

static void proc1(void)
{
	printf("proc1\n");
}

static void proc2(void)
{
	printf("proc2\n");
}
