#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void compute(int n);

int main(void)
{
	int n;
	int i;
	for (i = 0; i < 5; i++) {
		scanf("%d", &n);
		compute(n);
	}
	return 0;
}

/* DO NOT MODIFY THIS FUNCTION! */
void compute(int n)
{
	int x = 1 + n % 3;
	printf("compute(%d)\n", n);
	sleep(n);
}
