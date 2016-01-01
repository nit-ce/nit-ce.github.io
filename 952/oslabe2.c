#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void compute(int i);

void *thread(void *arg)
{
	int i;
	for (i = 0; i < 5; i++) {
		compute(i);
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	int i;
	pthread_t t1, t2, t3;
	pthread_create(&t1, NULL, thread, NULL);
	pthread_create(&t2, NULL, thread, NULL);
	pthread_create(&t3, NULL, thread, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

void compute(int i)
{
	printf("starting %d\n", i);
	sleep(1);
	printf("ending   %d\n", i);
}
