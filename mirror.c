#include <stdio.h>
#include "custom.h"

int main()
{
	int a, b, n, j = 0;
	printf("\nEnter the limits\t:\t");
	scanf("%d%d", &a, &b);
	n = a;
	do
	{
		int m = fcheck(n);
		if(m != 0)
			printf("\n%d => %d\n", n, m);		
		n++;
	}while(n <= b);	
}
