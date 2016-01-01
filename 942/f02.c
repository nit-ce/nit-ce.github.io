#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static char *owner_id;
static int owner_val;
static int stop;

static void waitabit(int val);

static void *thread1(void *v)
{
	int i;
	for (i = 500; !stop; i += 5) {
		waitabit(i % 11);
		owner_id = "one";
		owner_val = i;
	}
}

static void *thread2(void *v)
{
	int i;
	for (i = 700; !stop; i += 7) {
		waitabit(i % 11);
		owner_id = "two";
		owner_val = i;
	}
}

int main(void)
{
	pthread_t t1, t2;
	int i;
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	for (i = 0; i < 11; i++) {
		if (owner_id)
			printf("%s: %d\n", owner_id, owner_val);
		sleep(1);
	}
	stop = 1;
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS */

static void waitabit(int val)
{
	struct timespec ts;
	ts.tv_sec = val / 10;
	ts.tv_nsec = (val % 10) * 1e8;
	nanosleep(&ts, NULL);
}
