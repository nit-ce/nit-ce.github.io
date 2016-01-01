#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void A(void);
void B(void);

void C(void)
{
	/* MODIFY THIS FUNCTION */
	printf("C()\n");
}

int main(void)
{
	A();
	B();
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

void A(void)
{
	int n = rand() % 7;
	printf("A()\n");
	while (n--) {
		C();
		sleep(1);
	}
}

void B(void)
{
	int n = rand() % 7;
	printf("B()\n");
	while (n--) {
		C();
		sleep(1);
	}
}
