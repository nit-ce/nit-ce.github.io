#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int A(void);
int B(void);

int main(void)
{
	int x1 = A();
	int x2 = B();
	printf("Result: %d\n", x1 + x2);
	return 0;
}

/* DO NOT MODIFY THE FOLLOWING FUNCTIONS! */

int A(void)
{
	sleep(3);
	printf("A\n");
	return 98765;
}

int B(void)
{
	sleep(2);
	printf("B\n");
	return 54321;
}
