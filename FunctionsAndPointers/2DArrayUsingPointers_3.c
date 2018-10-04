#include "header.h"
#define MAX 100

void f(int (* ptr)[MAX], int m)
{
	int i, j;
	for(i = 0 ; i < m ; i++)
		for(j = 0 ; j < m ; j++)
			*(ptr[i] + j) += 1;
}

int main(int v, char * arg[])
{
	int a[MAX][MAX], m, i, j;
	scanf("%d", &m);

	int (*arr)[MAX] = (int *)a;

/*	for(i = 0 ; i < m ; i++)
		p[i] = *(a + i);
*/	 
	for(i = 0 ; i < m ; i++)
	{	
		int *p = (int *)(arr + i); 

		for(j = 0 ; j < m ; j++)
			scanf("%d", (p + j));
	}

	f(arr, m);
	
	printf("\n");
	for(i = 0 ; i < m ; i++)
	{
		for(j = 0 ; j < m ; j++)
			printf("%d ", *(*(arr + i) + j));
		printf("\n");
	}
}