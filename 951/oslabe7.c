#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void compute1(void);
void compute2(void);

int main(void)
{
	compute1();
	compute2();
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

void compute1(void)
{
	usleep(100000);
	printf("compute1()\n");
}

void compute2(void)
{
	usleep(100000);
	printf("compute2()\n");
}
