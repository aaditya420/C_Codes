#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int main()
{
	char s[MAX][MAX], *p[MAX], t[MAX], ch;
	int i, x, j, a[MAX], l;
	scanf("%d", &x);
	//Initialise pointer array
	for(i = 0 ; i < x ; i++)
		p[i] = *(s + i);
	//Enter elements
	for(i = 0 ; i < x ; i++)
		scanf("%s", p[i]);
	//Display elements
	printf("\nEntered strings\n");
	for(i = 0 ; i < x ; i++)
		printf("\n%d. %s\n", i + 1, p[i]);
	//Sort	
	printf("\nSorting...\n");
	for(i = 0 ; i < x ; i++)
	{	
		for(j = i ; j < x ; j++)
		{
						
			if(strcmp(p[i], p[j]) > 0)
			{
				strcpy(t, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], t);
			}
		}
	}
	//Display result	
	printf("\nResult\n");
	for(i = 0 ; i < x ; i++)
		printf("\n%d. %s\n", i + 1, p[i]);
	
	//Duplicate character remover
	int c = 0;	
	for(ch = 'a' ; ch <= 'z' ; ch++)
	{
		for(i = 0 ; i < x ; i++)
		{
			for(j = 0 ; *(p[i] + j) != '\0' ; j++)
			{				
				if(ch == tolower(*(p[i] + j)))
					c++;				
				if(ch == tolower(*(p[i] + j)) && c > 1)
					for(l = j ; *(p[i] + j) ; j++)
						*(p[i] + j) = *(p[i] + j + 1);		
							
			}
		}
	}

	//Display result	
	printf("\nResult\n");
	for(i = 0 ; i < x ; i++)
		printf("\n%d. %s\n", i + 1, p[i]);

	//Frequency finder
	i = 0;
	for(ch = 'a' ; ch <= 'z' ; ch++)
	{
		for(j = 0 ; *(p[i] + j) != '\0' ; j++)
		{
			if (ch == tolower(*(p[i] + j)))
			{
				*(a + i) += 1;
				i++;
			}
		}
	}


}



















