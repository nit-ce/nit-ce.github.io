#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int compute1(void);
int compute2(void);
int compute3(void);

static int first = -1;

static void *thread1(void *v)
{
	int n = compute1();
	first = n;
	return NULL;
}

static void *thread2(void *v)
{
	int n = compute2();
	first = n;
	return NULL;
}

static void *thread3(void *v)
{
	int n = compute3();
	first = n;
	return NULL;
}

int main(void)
{
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	int n;
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	pthread_create(&t3, NULL, thread3, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	printf("First: %d\n", first);
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

int compute1(void)
{
	usleep(250000);
	printf("compute1()\n");
	return 111;
}

int compute2(void)
{
	usleep(150000);
	printf("compute2()\n");
	return 222;
}

int compute3(void)
{
	usleep(350000);
	printf("compute3()\n");
	return 333;
}
