#include <stdio.h>

int main()
{
	FILE *f = fopen("temp.txt", "w");
	int x;

	printf("\nsizeof(int) = %dbytes\n", sizeof(int));

	int i = 0;
	do
	{
		printf("\nEnter number %d : ", ++i);
		scanf("%d", &x);
		putw(x, f);
	}while(x != 0);
	fclose(f);

	if((f = fopen("temp.txt", "r")) == NULL)
	{
		printf("\nUNABLE TO OPEN FILE\n");
		return -1;
	}

	i = 0;
	printf("\nFile content :\n");
	while((x = getw(f)) != EOF)
	{
		
		printf("\nEntered number %d : %d", ++i, x);
	}
	printf("\n");
}