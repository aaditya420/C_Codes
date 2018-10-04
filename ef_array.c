#include "custom.h"
#define MAX 100

int main(int v, char * arg[])
{
	if(v != atoi(arg[1]) + 2)
	{
		printf("\nerror : invalid arguments\n\n");
		return -1;
	}

	char fn[MAX], key[MAX], c;
	int i, ch;

	strcpy(fn, arg[1]);
	strcpy(key, arg[2]);
	ch = arg[3][0];

	FILE *f = fopen(fn, "r+");

	printf("\nEntered key\t:\t%s", key);
	print_content(fn);

	rewind(f);

	if(ch == 'e')
	{
		while((c = fgetc(f)) != EOF)
		{
			for(i = 0 ; i < strlen(key) ; i++)
			{
				c += key[i];
				fseek(f, -1, SEEK_CUR);
				fputc(c, f);
			}
		}
		printf("\nEncrypted Successfuly!\n");
		print_content(fn);
	}
	else if(ch == 'd')
	{
		while((c = fgetc(f)) != EOF)
		{
			for(i = 0 ; i < strlen(key) ; i++)
			{
				c -= key[i];
				fseek(f, -1, SEEK_CUR);
				fputc(c, f);
			}
		}
		printf("\nDecrypted Successfuly!\n");
		print_content(fn);
	}
	fclose(f);
}

