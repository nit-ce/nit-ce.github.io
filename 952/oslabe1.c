#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int verify(int a);

static int count;

int main(void)
{
	int i;
	for (i = 0; i < 5000; i++)
		if (verify(i))
			count++;
	printf("%d\n", count);
	return 0;
}

/* DO NOT MODIFY THESE FUNCTIONS! */

static long gcd(long a, long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

static int verify(int a)
{
	int i;
	int n = 0;
	for (i = 2; i < a; i++)
		if (gcd(a, i) == 1)
			n++;
	return (n % 5) == 0;
}

