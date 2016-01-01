#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void compute1(void);
void compute2(void);
void compute3(void);

static void *thread1(void *v)
{
	return NULL;
}

int main(void)
{
	pthread_t t1;
	int i;
	pthread_create(&t1, NULL, thread1, NULL);
	compute1();
	compute2();
	compute3();
	pthread_join(t1, NULL);
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

void compute1(void)
{
	printf("compute1()\n");
}

void compute2(void)
{
	printf("compute2()\n");
}

void compute3(void)
{
	printf("compute3()\n");
}
