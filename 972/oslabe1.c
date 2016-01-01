#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void f(int i);
void g(int i);

static void *thread1(void *v)
{
	f(1);
	g(1);
	return NULL;
}

static void *thread2(void *v)
{
	f(2);
	g(2);
	return NULL;
}

int main(void)
{
	/* create the threads ... */
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

void f(int i)
{
	printf("f%d\n", i);
	sleep(1);
}

void g(int i)
{
	printf("g%d\n", i);
	sleep(1);
}
