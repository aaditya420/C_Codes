#include <stdio.h>

int main()
{
	int const x = 10;
	int *px = &x;
	*(px)++;
	printf("%d\t%d", *px, x);
}