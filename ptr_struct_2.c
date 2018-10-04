/*
	Program to find the quadrant for entered coordinates

	usage : ./ptr_struct_1 x1 y1 x2 y2...
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct coordinates
{
	int x;
	int y;
	int quad;
}c;

int main(int v, char * arg[])
{
	
	c a[MAX], *pa = a;
	int i = 0, j = 0, c = 1;

	while(arg[c] != NULL)
	{
		(pa + i) -> x = atoi(arg[c]);
			c++;

		(pa + i) -> y = atoi(arg[c]);
			c++;

		(pa + i) -> quad = 0;

		if(((pa + i) -> x > 0) && ((pa + i) -> y > 0))
			(pa + i) -> quad = 1;

		else if(((pa + i) -> x < 0) && ((pa + i) -> y > 0))
			(pa + i) -> quad = 2;
		
		else if(((pa + i) -> x < 0) && ((pa + i) -> y < 0))
			(pa + i) -> quad = 3;
		
		else if(((pa + i) -> x > 0) && ((pa + i) -> y < 0))
			(pa + i) -> quad = 4;

		i++;
	}

	j = i;

	printf("Entered data : \n");
	for(i = 0 ; i < j ; i++)
		printf("%d.(%d, %d)\t= Quadrant - %d\n", i + 1, (pa + i) -> x, (pa + i) -> y, (pa + i) -> quad);
}