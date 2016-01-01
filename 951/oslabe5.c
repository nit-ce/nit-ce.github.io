#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int compute1(void);
int compute2(void);

static void *thread1(void *v)
{
	compute1();
	return NULL;
}

int main(void)
{
	pthread_t t1;
	int n;
	pthread_create(&t1, NULL, thread1, NULL);
	n = compute2();
	printf("Sum: %d\n", n);
	pthread_join(t1, NULL);
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

int compute1(void)
{
	printf("compute1()\n");
	return 111;
}

int compute2(void)
{
	printf("compute2()\n");
	return 222;
}
