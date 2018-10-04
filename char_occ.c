/*
	Program to count the occurence of input character 
	in a given list of strings using pointers

	usage : ./char_occ number_of_strings character
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(int v, char * arg[])
{
	if(v != 3)
	{
		printf("usage : ./char_occ number_of_strings character\n");
		return -1;
	}

	char s[MAX][MAX], *p[MAX], ch;
	int i, j, n, c = 0;

	for(i = 0 ; i < MAX ; i++)
		p[i] = *(s + i);

	n = atoi(arg[1]);
	ch = arg[2][0];

	for(i = 0 ; i < n ; i++)
		fgets(p[i], MAX, stdin);

	printf("\nEntered character\t: %c", ch);
	printf("\nEntered list\t: \n");
	for(i = 0 ; i < n ; i++)
		printf("%d.%s", i + 1, p[i]);

	for(i = 0 ; i < n ; i++)
		for(j = 0 ; *(p[i] + j) != '\0' ; j++)
			if(*(p[i] + j) == ch)
				c++;

	printf("\nThe given list has %c ocurring %d times\n", ch, c);
}