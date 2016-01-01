#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void f(int i);

static int sum;
static int count = 30;

static void *thread1(void *v)
{
	int i;
	while (1) {
		if (count <= 0)
			break;
		count--;
		sum += i * 23;
		usleep(50000);
	}
	return NULL;
}

int main(void)
{
	pthread_t t1;
	int i;
	pthread_create(&t1, NULL, thread1, NULL);
	while (1) {
		if (count <= 0)
			break;
		count--;
		printf("last: %d\n", sum);
		usleep(100000);
	}
	pthread_join(t1, NULL);
	return 0;
}
