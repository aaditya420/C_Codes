#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void print_content(char fn[])
{
	 FILE *f = fopen(fn, "r");
	 char c;
	 printf("\nFile content\t:\t\n");
	 while((c = fgetc(f)) != EOF)
	 	printf("%c", c);
	 printf("\n\n");
	 fclose(f);
}

int pscheck(int n)
{
	int i;
	for(i = 1 ; i <= n ; i++)
		if(n == i * i)
			return i;
	if(i == n + 1)
		return 0;
}

int fcheck(int n)
{
		int t, r, f = 1, m = 0, t1, i = 0;
		t = t1 = n;
		while(t1)
		{
			i++;
			t1 /= 10;
		}
	//	printf("\ni => %d\n", i);
		i--;
		while(t)
		{
			r = t % 10;
			t /= 10;
	//		printf("\ni => %d\nr => %d\n", i, r);
			if(r == 0)
				i--;
			else if(r == 1)
			{
				m += 1 * (pow(10, i));
	//			printf("\nm => %d", m);
				i--;
			}
			else if(r == 6)
			{
				m += 9 * (pow(10, i));
	//			printf("\nm => %d", m);
				i--;
			}
			else if(r == 8)
			{
				m += 8 * (pow(10, i));
	//			printf("\nm => %d", m);
				i--;
			}
			else if(r == 9)
			{
				m += 6 * (pow(10, i));
	//			printf("\nm => %d", m);
				i--;
			}
			else
			{
				f = 0;
				break;
			}
		}

		if(f == 1)
			return m;
		else 
		if(f == 0)
			return 0;
}