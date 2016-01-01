#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void A(void);
void B(void);

void *thread1(void *arg)
{
	int i;
	for (i = 0; i < 4; i++)
		A();
	return NULL;
}

void *thread2(void *arg)
{
	int i;
	for (i = 0; i < 4; i++)
		A();
	return NULL;
}

void *thread3(void *arg)
{
	B();
	return NULL;
}

int main(void)
{
	int i;
	pthread_t t1, t2, t3;
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	pthread_create(&t3, NULL, thread3, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	return 0;
}

/* DO NOT MODIFY THE FOLLOWING FUNCTIONS! */

void A(void)
{
	sleep(1);
	printf("A\n");
}

void B(void)
{
	sleep(2);
	printf("B\n");
}
