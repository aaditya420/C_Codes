/*
	Program to sort a given list of strings in lexographical order.
	Using pointers.

	usage : ./dict_sort number_of_strings
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
		for(j = i ; j < n ; j++)
			if(strcmp(p[i], p[j]) > 0)
			{
				char t[MAX];
				strcpy(t, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], t);
			}

	printf("\nSorted list : \n");
	for(i = 0 ; i < n ; i++)
		printf("%d.%s", i + 1, p[i]);
}