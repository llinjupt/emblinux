#include <stdio.h>
#include <stdlib.h>

int hello(int a, int b ,int c, int d)
{
	printf("a: %p, b: %p, c:%p, d:%p\n", &a, &b, &c, &d);
	return 1;
}

int main()
{
	int a , b,c, d;
	printf("a: %p, b: %p, c:%p, d:%p\n", &a, &b, &c, &d);
	char *p = malloc(100);
	hello(a, b, c, d);
	printf("malloc:%p\n", p);
	return 0;
}
