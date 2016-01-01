#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int findrate(int x);

int A[100];
int sum = 0;

int main(void)
{
	int x;
	int i;
	for (i = 0; i < 100; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 0; i < 100; i++) {
		x = findrate(A[i]);
		sum += x;
	}
	printf("Sum: %d\n");
	return 0;
}

/* DO NOT MODIFY THE FOLLOWING FUNCTIONS! */

int findrate(int x)
{
	usleep(100000 + (x % 25) * 5000);
	printf("findrate: %d\n", x);
	return x * 5;
}
