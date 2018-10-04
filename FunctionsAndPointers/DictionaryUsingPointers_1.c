#include "header.h"
#define MAX 100

void f(char * p[MAX], int m)
{
	int i, j;
	for(i = 0 ; i < m ; i++)
	{
		for(j = i ; j < m ; j++)
		{
			if(strcmp(p[i], p[j]) > 0)
			{
				char t[MAX];
				strcpy(t, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], t);
			}
		}
	}
}

int main(int v, char * arg[])
{
	char a[MAX][MAX], *p[MAX];
	int m, i, j;
	scanf("%d", &m);

	for(i = 0 ; i < m ; i++)
		p[i] = *(a + i);
	
	for(i = 0 ; i < m ; i++)
		//for(j = 0 ; j < m ; j++)
			scanf("%s", p[i]);
	
	f(p, m);
	
	for(i = 0 ; i < m ; i++)
		printf("%s\n", (p[i]));
}