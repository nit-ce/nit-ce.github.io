#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void A(void);
void B(void);

int main(void)
{
	A();
	B();
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

void A(void)
{
	sleep(rand() % 5);
}

void B(void)
{
	sleep(rand() % 5);
}
