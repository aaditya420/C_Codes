/*
	Program to find the gem element from a list of strings.
	Gem element is one that occurs in every string.

	usage : ./gem_element number_of_strings
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main(int v, char * arg[])
{
	if(v != 2)
	{
		printf("usage : ./dict_sort number_of_strings\n");
		return -1;
	}

	char s[MAX][MAX], *p[MAX];
	int i, j, n;

	for(i = 0 ; i < MAX ; i++)
		p[i] = *(s + i);

	n = atoi(arg[1]);

	for(i = 0 ; i < n ; i++)
		fgets(p[i], MAX, stdin);

	printf("\nEntered list : \n");
	for(i = 0 ; i < n ; i++)
		printf("%d.%s", i + 1, p[i]);

	for(i = 0 ; i < n ; i++)
	{
		
	}

	printf("\nSorted list : \n");
	for(i = 0 ; i < n ; i++)
		printf("%d.%s", i + 1, p[i]);
}