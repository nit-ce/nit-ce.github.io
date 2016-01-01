#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int compute1(void);
int compute2(void);

int main(void)
{
	if (fork() == 0) {
		compute1();
	} else {
		int n = compute2();
		printf("Sum: %d\n", n);
	}
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

int compute1(void)
{
	printf("compute1()\n");
	return 111;
}

int compute2(void)
{
	printf("compute2()\n");
	return 222;
}
