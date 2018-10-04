#include "header.h"
#define MAX 100

typedef struct coordinates
{
	int x, y;
}X;

void f(X * c, int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		(c + i)->x += 1;
		(c + i)->y += 1;
	}
}

int main()
{
	X c[MAX], *p=c;
	int n, i;
	scanf("%d", &n);
	
	for(i = 0 ; i < n ; i++)
		scanf("%d%d", &c[i].x, &c[i].y);

	printf("\nEntered coordinates : \n");
	for(i = 0 ; i < n ; i++)
		printf("(%d, %d)\n", c[i].x, c[i].y);	


	f(p , n);

	printf("\nModified coordinates : \n");
	for(i = 0 ; i < n ; i++)
		printf("(%d, %d)\n", c[i].x, c[i].y);	

}