#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main(int v, char * arg[])
{
	if(v != 2)
	{
		printf("invalid arguments\n");
		return -1;
	}

	int a[MAX], i = 1, n, f = 1, j;

	n = atoi(arg[1]);
	
	printf("\nEnter the numbers : \n");
	for(i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	
	printf("\nEntered integers are : \n");
	for(i = 0 ; i < n ; i++)
		printf("%d\n", a[i]);

	FILE *in, *pr, *comp;

	in = fopen("integer.txt", "w");
	for(i = 0 ; i < n ; i++)
		putw(a[i], in);
	fclose(in);

	if((in = fopen("integer.txt", "r")) == NULL)
	{
		printf("\nFILE NOT FOUND!\n");
		return -1;
	}

	i = 0;
	while(!feof(in))
	{
		a[i] = getw(in);
		//printf("\n%d %d", a[i], i);
		i++;
	}

	n = i;
	pr = fopen("prime.txt", "w");
	comp = fopen("composite.txt", "w");

	for(i = 0 ; i < n ; i++)
	{
		f = 1;
		for(j = 2 ; j <= a[i] / 2  ; j++)
			if(a[i] % j == 0)
			{
				f = 0;
				break;
			}

		if(f == 0)
			putw(a[i], comp);
		else
			putw(a[i], pr);	
	}
	fclose(pr);
	fclose(comp);

	i = 0;
	if((pr = fopen("prime.txt", "r")) == NULL)
	{
		printf("\nFILE NOT FOUND!\n");
		return -1;
	}
	printf("\nThe contents of prime.txt are :\n");
	while(!feof(pr))
	{
		a[i] = getw(pr);
		printf("%d\n", a[i]);
		i++;
	}
	fclose(pr);
	if((comp = fopen("composite.txt", "r")) == NULL)
	{
		printf("\nFILE NOT FOUND!\n");
		return -1;
	}
	i = 0;
	printf("\nThe contents of composite.txt are : \n");
	while(!feof(comp))
	{
		a[i] = getw(comp);
		printf("%d\n", a[i]);
		i++;
	}

}