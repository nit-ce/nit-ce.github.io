#include <stdio.h>

int prod(int p);
int cons(int p);

int main(void)
{
	int i;
	for (i = 0; i < 10; i++) {
		int dat1 = prod(i);
		cons(dat1);
	}
	return 0;
}

/* the definition of functions that perform the computation */

int prod(int p)
{
	printf("prod: %d\n", p);
	return p;
}

int cons(int p)
{
	printf("cons: %d\n", p);
	return p;
}
