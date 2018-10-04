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
	char a[MAX][MAX], *arr = (char *)a;
	int m, i, j;
	scanf("%d", &m);

/*	for(i = 0 ; i < m ; i++)
		p[i] = *(a + i);
*/	
	for(i = 0 ; i < m ; i++)
		for(j = 0 ; arr + i ; j++)
			scanf("%s", (arr + j));
	
	//f(arr, m);
	
	printf("\n");
	for(i = 0 ; i < m ; i++)
	{
		//for(j = 0 ; j < m ; j++)
			printf("%s\n", arr[i]);
		//printf("\n");
	}
}