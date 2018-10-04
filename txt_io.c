#include <stdio.h>
#include <stdlib.h>

int main(int v, char **arg)
{
	FILE *f = fopen("integers.txt", "wb");
	int i = 0;
	while(i < atoi(arg[1]))
	{
		putw(i, f);
		i++;
	}
	fclose(f);

	f = fopen("integers.txt", "rb");
	while(!feof(f))
	{
		i = getw(f);
		printf("%d\n", i);
	}
	fclose(f);
}