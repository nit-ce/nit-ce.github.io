#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int found;

static void *search(void *arg)
{
	int i;
	for (i = 0;; i++) {
		found = i * 3;
		sleep(1);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_create(&tid, NULL, search, NULL);
	pthread_join(tid, NULL);
	return 0;
}
