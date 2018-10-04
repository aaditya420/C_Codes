#include "header.h"
#define MAX 100

void f(int * ptr[], int m)
{
	int i, j;
	for(i = 0 ; i < m ; i++)
		for(j = 0 ; j < m ; j++)
			*(ptr[i] + j) += 1;
}

int main(int v, char * arg[])
{
	int a[MAX][MAX], *p[MAX], m, i, j;
	scanf("%d", &m);

	for(i = 0 ; i < m ; i++)
		p[i] = *(a + i);
	
	for(i = 0 ; i < m ; i++)
		for(j = 0 ; j < m ; j++)
			scanf("%d", (*(p + i) + j));
	
	f(p, m);
	
	printf("\n");
	for(i = 0 ; i < m ; i++)
	{
		for(j = 0 ; j < m ; j++)
			printf("%d ", *(p[i] + j));
		printf("\n");
	}
}