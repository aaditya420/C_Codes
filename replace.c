/*
	Program to replace input char with another using pointers.

	usage : ./change_case input_string char_1 char_2
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main(int v, char * arg[])
{
	if(v != 4)
	{
		printf("usage : ./change_case input_string char_1 char_2\n");
		return -1;
	}

	int i;
	char s[MAX], *ps = s, char_1, char_2;
	strcpy(s, arg[1]);
	char_1 = arg[2][0];
	char_2 = arg[3][0];

	for(i = 0 ; i < strlen(s) ; i++)
		if(*(ps + i) == char_1)
			*(ps + i) = char_2;

	printf("Converted string : %s\n", s);
}
