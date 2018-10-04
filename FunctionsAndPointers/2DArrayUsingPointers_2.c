#include "header.h"
#define MAX 100

void f(int * ptr, int m)
{
	int i, j;
	for(i = 0 ; i < m ; i++)
		for(j = 0 ; j < m ; j++)
			*(ptr + i * m + j) += 1;
}

int main(int v, char * arg[])
{
	int a[MAX][MAX], *arr = (int *)a, m, i, j;
	scanf("%d", &m);

/*	for(i = 0 ; i < m ; i++)
		p[i] = *(a + i);
*/	
	for(i = 0 ; i < m ; i++)
		for(j = 0 ; j < m ; j++)
			scanf("%d", (arr + i * m + j));
	
	f(arr, m);
	
	printf("\n");
	for(i = 0 ; i < m ; i++)
	{
		for(j = 0 ; j < m ; j++)
			printf("%d ", *(arr + i * m + j));
		printf("\n");
	}
}