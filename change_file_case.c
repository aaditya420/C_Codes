#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int main(int v, char * arg[])
{
	if(v != 2)
	{
		printf("invalid arguments\n");
		return -1;
	}

	FILE *f;

	if((f = fopen(arg[1], "r")) == NULL)
	{
		printf("\nERROR OPENING %s", arg[1]);
		return -1;
	}

	char ch;
	while(!feof(f))
	{
		if(isupper(ch = getc(f)))
			printf("%c", tolower(ch));
		else
			printf("%c", toupper(ch));
	}

	fclose(f);
}