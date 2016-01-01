#include <stdio.h>
#include <unistd.h>

void comp(int p);

int main(void)
{
	int i;
	for (i = 0; i < 10; i++)
		comp(i);
	return 0;
}

/* the definition of computation functions; DO NOT CHANGE THESE! */

void comp(int p)
{
	sleep((p * 7 + 5) % 3 + 1);
	printf("Finished comp(%d)\n", p);
}
