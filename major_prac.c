#include <stdio.h>
#include <limits.h>

#define MAX 100

int main()
{
	int a[MAX], *pa = a, n, i, j;

	printf("\nEnter n : ");
	scanf("%d", &n);

	printf("\nEnter the elements of array : \n");
	for(i = 0 ; i < n ; i++)
		scanf("%d", (pa + i));

	int min = INT_MAX;
	for(i = 0 ; i < n ; i++)
		if(*(pa + i) < min)
			min = *(pa + i);

	int f = 0, x = min + 1;
	for(i = 0 ; i < n - 1 ; i++)
	{
		f = 0;
		for(j = 0 ; j < n ; j++)
			if(*(pa + j) == x)
			{
				f = 1;
				break;
			}
		if(f == 0)
		{
			printf("\nFALSE\n");
			break;
		}
		else
			x++;
	}
	if(i == n - 1)
	{
		printf("\nTRUE\n");
		return 0;
	}
	else
		return -1;
}