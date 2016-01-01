#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int A(void);
int B(void);
int C(void);

static int first = 0;
static int first_id = 0;

static void *thread1(void *v)
{
	int n = A();
	first = n;
	first_id = 1;
	return NULL;
}

static void *thread2(void *v)
{
	int n = B();
	first = n;
	first_id = 2;
	return NULL;
}

static void *thread3(void *v)
{
	int n = C();
	first = n;
	first_id = 3;
	return NULL;
}

int main(void)
{
	int n;
	/* create the threads ... */
	printf("First call: %d\n", first_id);
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

int A(void)
{
	usleep(250000);
	printf("A()\n");
	return 1;
}

int B(void)
{
	usleep(150000);
	printf("B()\n");
	return 2;
}

int C(void)
{
	usleep(350000);
	printf("C()\n");
	return 3;
}
