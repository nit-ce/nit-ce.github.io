#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void f(void);
static void g(void);
static void h(void);
static void i(void);
static void j(void);

static void *thread1(void *v)
{
	f();
	i();
}

static void *thread2(void *v)
{
	g();
	j();
}

static void *thread3(void *v)
{
	h();
}

int main(void)
{
	pthread_t t1, t2, t3;
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	pthread_create(&t3, NULL, thread3, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
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

static void i(void)
{
	printf("i()\n");
}

static void j(void)
{
	printf("j()\n");
}
