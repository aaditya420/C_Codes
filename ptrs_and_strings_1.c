/*
	Program to encrypt or decrypt the given 
	string using the vigenere cipher
	based on user's choice using pointers

	./ptrs_and_strings_1 input_string key option(1 - Encrypt, 2 - Decrypt, 0 - Do nothing)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARG		4
#define MAX_SIZE 	100

int main(int argc, char * argv[])
{
	if(argc != MAX_ARG)
	{
		printf("usage : ./ptrs_and_strings_1 input_string key option(1 - Encrypt, 2 - Decrypt, 0 - Do nothing)\n");
		return -1;
	}

	char 	s[MAX_SIZE];
	char	k[MAX_SIZE];
	char	*ps = s;
	char 	*pk = k;
	int 	op;
	int 	i, j;
	int 	ls = 0, lk = 0;

	strcpy(s, argv[1]);
	strcpy(k, argv[2]);
	op = atoi(argv[3]);

	printf("\nEntered string\t: %s\nEntered key\t: %s\nEntered option\t: %d\n\n", s, k, op);

	while(*ps != '\0')
	{
		ls++;
		ps++;
	}

	while(*pk != '\0')
	{
		lk++;
		pk++;
	}

	ps = s;
	pk = k;

	if(op == 1)
	{
		for(i = 0, j = 0 ; i < ls ; i++, j++)
		{
			if(j == lk)
				j = 0;

			int x = (*(ps + i) + *(pk + j)) % 26;

			x += 'A';

			*(ps + i) = (char)x;
		}

		printf("\nEncrypted string\t: %s\n\n", s);
	}
	else if(op == 2)
	{
		for(i = 0, j = 0 ; i < ls ; i++, j++)
		{
			if(j == lk)
				j = 0;

			int x = (*(ps + i) - *(pk + j) + 26) % 26;

			x += 'A';

			*(ps + i) = (char)x;
		}

		printf("\nDecrypted string\t: %s\n\n", s);			
	}
}