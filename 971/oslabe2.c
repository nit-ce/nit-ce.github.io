#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void A(void);
void B(void);
void C(void);
void D(void);

int main(void)
{
	A();
	B();
	C();
	D();
	return 0;
}

/* DO NOT MODIFY THE FOLLOWING FUNCTIONS! */

void A(void)
{
	sleep(2);
	printf("A\n");
}

void B(void)
{
	sleep(3);
	printf("B\n");
}

void C(void)
{
	sleep(1);
	printf("C\n");
}

void D(void)
{
	sleep(2);
	printf("D\n");
}
