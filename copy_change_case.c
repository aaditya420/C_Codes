#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int main(int v, char * arg[])
{
	if(v != 3)
	{
		printf("invalid arguments\n");
		return -1;
	}

	FILE *f1 = fopen(arg[1], "r");
	FILE *f2 = fopen(arg[2], "w");

	if(f1 == NULL)
	{
		printf("\nERROR OPENING %s\n", arg[1]);
		return -1;
	}

	char ch;
	while(!feof(f1))
	{
		if(islower((ch = getc(f1))))
			ch = toupper(ch);
		putc(ch, f2);
	}

	fclose(f1);
	fclose(f2);

}