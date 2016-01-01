#include <ctype.h>
#include <errno.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PRINT(s)	write(1, (s), strlen(s))

extern char **environ;

static int test_str(void)
{
	char *s1 = "123";
	char s2[10] = "34";
	if (strlen(s1) != 3 || strlen(s2) != 2)
		return 1;
	if (strchr(s1, '1') != s1 || strchr(s1, '3') != s1 + 2)
		return 2;
	if (strchr(s1, 'x') != NULL)
		return 3;
	if (!strcmp(s1, s2))
		return 4;
	if (strcmp(s1, s1))
		return 5;
	strcpy(s2, s1);
	if (strcmp(s1, s2))
		return 6;
	if (strrchr(s1, '4'))
		return 7;
	if (strrchr(s1, '1') != s1)
		return 8;
	if (strrchr(s1, '3') != s1 + 2)
		return 9;
	return 0;
}

static int test_str2(void)
{
	char *s1 = "1235";
	char *s2 = "1234";
	if (strncmp(s1, s2, 0))
		return 1;
	if (strncmp(s1, s2, 1))
		return 2;
	if (strncmp(s1, s2, 3))
		return 3;
	if (!strncmp(s1, s2, 4))
		return 4;
	if (!strncmp(s1, "123", 4))
		return 5;
	return 0;
}

static int test_mem(void)
{
	char s1[10] = "123";
	char s2[10] = "456";
	char s3[11];
	if (memcpy(s2, s1, 4) != s2)
		return 1;
	if (strcmp("123", s2))
		return 2;
	memset(s2, 0, 4);
	if (s2[0] || s2[1] || s2[2] || s2[3])
		return 3;
	memcpy(s3, "abcde", 6);
	memmove(s3, s3 + 2, 2);
	if (strcmp("cdcde", s3))
		return 4;
	memcpy(s3, "abcde", 6);
	memmove(s3, s3 + 1, 3);
	if (strcmp("bcdde", s3))
		return 5;
	memcpy(s3, "abcde", 6);
	memmove(s3 + 2, s3, 3);
	if (strcmp("ababc", s3))
		return 6;
	return 0;
}

static int test_mem2(void)
{
	char s1[10] = "123";
	char s2[10] = "1245";
	if (memcmp(s1, s2, 0))
		return 1;
	if (memcmp(s1, s2, 2))
		return 2;
	if (memcmp(s1, s2, 3) >= 0)
		return 3;
	if (memcmp(s2, s1, 4) <= 0)
		return 4;
	return 0;
}

static int test_mem3(void)
{
	char s1[10] = "113";
	if (memchr(s1, '3', 2))
		return 1;
	if (memchr(s1, '3', 3) != s1 + 2)
		return 2;
	if (memchr(s1, '1', 3) != s1)
		return 3;
	if (memchr(s1, '1', 0))
		return 7;
	return 0;
}

static int test_malloc(void)
{
	int *a, *b;
	char *c;
	int i;
	a = malloc(sizeof(*a) * 100);
	if (!a)
		return 1;
	for (i = 0; i < 100; i++)
		a[i] = i;
	b = malloc(sizeof(*b));
	*b = 123;
	for (i = 0; i < 100; i++)
		if (a[i] != i)
			return 2;
	if (*b != 123)
		return 3;
	c = malloc(1 << 20);
	if (!c)
		return 4;
	if (malloc(1 << 30))
		return 5;
	free(a);
	free(c);
	free(b);
	return 0;
}

static int test_stdlib(void)
{
	if (atoi("123") != 123)
		return 1;
	if (atoi("-123") != -123)
		return 2;
	return 0;
}

static int icmp(void *i1, void *i2)
{
	return *(int *) i1 - *(int *) i2;
}

static int test_sort(void)
{
	int a1[] = {1, 2, 3, 4};
	int a2[] = {3, 2, 4, 1};
	int a3[] = {4, 3, 2, 1};
	qsort(a1, 4, sizeof(int), (void *) icmp);
	qsort(a2, 4, sizeof(int), (void *) icmp);
	qsort(a3, 4, sizeof(int), (void *) icmp);
	if (a1[0] != 1 || a1[1] != 2 || a1[2] != 3 || a1[3] != 4)
		return 1;
	if (a2[0] != 1 || a2[1] != 2 || a2[2] != 3 || a2[3] != 4)
		return 2;
	if (a3[0] != 1 || a3[1] != 2 || a3[2] != 3 || a3[3] != 4)
		return 3;
	return 0;
}

static int test_ctype(void)
{
	if (!isalpha('a') || !isalpha('B') || isalpha('2'))
		return 1;
	if (!isdigit('2') || isdigit('b'))
		return 2;
	if (toupper('a') != 'A' || tolower('B') != 'b')
		return 3;
	if (toupper('1') != '1')
		return 4;
	if (!isblank(' ') || isblank('a'))
		return 5;
	return 0;
}

int sum(int n, ...)
{
	int i;
	int s = 0;
	va_list ap;
	va_start(ap, n);
	for (i = 0; i < n; i++)
		s += va_arg(ap, int);
	va_end(ap);
	return s;
}

static int test_stdarg(void)
{
	if (sum(0) != 0)
		return 1;
	if (sum(1, 10) != 10)
		return 2;
	if (sum(3, 100000, 10000, 1000) != 111000)
		return 3;
	return 0;
}

static int test_stdio(void)
{
	char buf[100];
	sprintf(buf, "a:%s b:%d c:%x\n", "abc", 123, 0xdef);
	if (strcmp("a:abc b:123 c:def\n", buf))
		return 1;
	sprintf(buf, "%3d-%3s-%03x\n", -1, "a", 3);
	if (strcmp(" -1-  a-003\n", buf))
		return 2;
	snprintf(buf, 5, "something %s", "more!");
	if (strcmp("some", buf))
		return 3;
	snprintf(buf, 5, "s%s", "more!");
	if (strcmp("smor", buf))
		return 4;
	return 0;
}

static int test_stdio2(void)
{
	char *s = "abc 123 efg=(456)\n";
	char s1[4], s2[4];
	int a, b;
	if (sscanf("abc", "abc") != 0)
		return 9;
	if (sscanf(" abc ", "abc") != 0)
		return 10;
	if (sscanf(s, "%s %d", s1, &a) != 2)
		return 1;
	if (a != 123 || strcmp("abc", s1))
		return 2;
	if (sscanf(s, "%s %d efg=(%d)", s1, &a, &b) != 3)
		return 3;
	if (a != 123 || strcmp("abc", s1) || b != 456)
		return 4;
	if (sscanf("abc   \n  efg\n", "%s %s", s1, s2) != 2)
		return 5;
	if (strcmp("abc", s1) || strcmp("efg", s2))
		return 6;
	if (sscanf("321cba", "%d%s", &a, s1) != 2)
		return 7;
	if (*strchr(s1, 'd') != 'd')
		return 7;
	if (a != 321 || strcmp("cba", s1))
		return 8;
	if (sscanf("abc123", "%1s%3s%1d%1d", s1, s2, &a, &b) != 4)
		return 9;
	if (strcmp("a", s1) || strcmp("bc1", s2) || a != 2 || b != 3)
		return 10;
	return 0;
}

static int test_net(void)
{
	if (ntohs(0x1234) != 0x3412)
		return 1;
	if (htons(0x1234) != 0x3412)
		return 2;
	if (ntohl(0x12345678) != 0x78563412)
		return 3;
	if (htonl(0x12345678) != 0x78563412)
		return 4;
	return 0;
}

static jmp_buf jbuf;
static int jcnt;

static int dojmp(void)
{
	longjmp(jbuf, jcnt++);
	return 1;
}

static int test_jmp(void)
{
	while (setjmp(jbuf) < 3)
		return dojmp();
	if (jcnt != 4)
		return 2;
	return 0;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	if (ret = test_str())
		PRINT("str failed\n");
	if (ret = test_str2())
		PRINT("str2 failed\n");
	if (ret = test_mem())
		PRINT("mem failed\n");
	if (ret = test_mem2())
		PRINT("mem2 failed\n");
	if (ret = test_mem3())
		PRINT("mem3 failed\n");
	if (ret = test_malloc())
		PRINT("malloc failed\n");
	if (ret = test_stdlib())
		PRINT("stdlib failed\n");
	if (ret = test_sort())
		PRINT("sort failed\n");
	if (ret = test_ctype())
		PRINT("ctype failed\n");
	if (ret = test_stdarg())
		PRINT("stdarg failed\n");
	if (ret = test_stdio())
		PRINT("stdio failed\n");
	if (ret = test_stdio2())
		PRINT("stdio2 failed\n");
	if (ret = test_net())
		PRINT("net failed\n");
	if (ret = test_jmp())
		PRINT("jmp failed\n");
	return ret;
}
