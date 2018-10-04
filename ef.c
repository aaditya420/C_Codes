#include "custom.h"
#define MAX 100

int main(int v, char * arg[])
{
	if(v != 4)
	{
		printf("\nerror : invalid arguments\n\n");
		return -1;
	}

	char fn[MAX], key[MAX], c[MAX];
	int i, ch, j;

	strcpy(fn, arg[1]);
	strcpy(key, arg[2]);
	ch = arg[3][0];

	FILE *f = fopen(fn, "r+");

	printf("\nEntered key\t:\t%s", key);
	print_content(fn);

	rewind(f);

	if(ch == 'e')
	{
		while((fgets(c, MAX, f)) != NULL)
		{
			for (i = 0, j = 0; i < strlen(c); i++, j++)
			{
				if(j == strlen(key))
					j = 0;

				int x = c[i] + key[j];
				x += 'A';

				c[i] = (char)x;
			}

			fseek(f, -strlen(c), SEEK_CUR);
			fputs(c, f);
		}
		fclose(f);
		printf("\nEncrypted Successfuly!\n");
		print_content(fn);
	}
	/*else if(ch == 'd')
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
	fclose(f);*/
}

