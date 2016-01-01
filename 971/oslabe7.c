#include <stdio.h>
#include <unistd.h>

void A(void);
void B(void);

int main(void)
{
	int i;
	for (i = 0; i < 5; i++)
		A();
	for (i = 0; i < 5; i++)
		B();
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
	sleep(1);
	printf("B\n");
}
