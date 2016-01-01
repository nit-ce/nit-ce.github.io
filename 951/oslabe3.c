#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void compute1(void);
void compute2(void);
void compute3(void);

static void *thread1(void *v)
{
	return NULL;
}

int main(void)
{
	compute1();
	compute2();
	compute3();
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

void compute1(void)
{
	sleep(2);
	printf("compute1()\n");
}

void compute2(void)
{
	sleep(1);
	printf("compute2()\n");
}

void compute3(void)
{
	printf("compute3()\n");
}
