/*
	Program to change case of the given string 
	based on user's choice using pointers.

	usage : ./change_case input_string case(u - change to upper case, l - change to lower case)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main(int v, char * arg[])
{
	if(v != 3)
	{
		printf("usage : ./change_case input_string case(u - change to upper case, l - change to lower case)\n");
		return -1;
	}

	int i;
	char s[MAX], *ps = s, op;
	strcpy(s, arg[1]);
	op = arg[2][0];

	if(op == 'u' || op == 'U')
		for(i = 0 ; i < strlen(s) ; i++)
				*(ps + i) = toupper(*(ps + i));

	else if(op == 'l' || op == 'L')
		for(i = 0 ; i < strlen(s) ; i++)
				*(ps + i) = tolower(*(ps + i));

	else
	{
		printf("usage : ./change_case input_string case(u - change to upper case, l - change to lower case)\n");
		return -1;
	}

	printf("Converted string : %s\n", s);

}