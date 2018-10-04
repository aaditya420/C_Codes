/*
	Program to enter details of n students and print their 
	details sorted on the basis of marks using pointers.

	usage : ./std_info number of records
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct student
{
	int rno;
	char name[MAX];
	float cgpa;
}S;

int main(int v, char * arg[])
{
	if(v != 2)
	{
		printf("usage : ./std_info number of records\n");
		return -1;
	}

	S a[MAX], *pa = a;
	int n = atoi(arg[1]);

	int i;
	for(i = 0 ; i < n ; i++)
	{
		printf("\nEnter details for student %d\n", i + 1);
		printf("\nRoll no.\t: ");
		scanf("%d", &(pa + i) -> rno);
		getchar();
		printf("\nName\t: ");
		fgets((pa + i) -> name, MAX, stdin);
		printf("\nCGPA\t: ");
		scanf("%f", &(pa + i) -> cgpa);
	}

	int j;
	for(i = 0 ; i < n ; i++)
	{
		for(j = i ; j < n ; j++)
		{
			if((pa + i) -> cgpa > (pa + j) -> cgpa)
			{
				S t;
				t = *(pa + i);
				*(pa + i) = *(pa + j);
				*(pa + j) = t;
			}
		}
	}

	printf("\nSorted Records\n");
	for(i = 0 ; i < n ; i++)
	{
		printf("\nRecord %d\n", i + 1);
		printf("\nRoll no.\t: %d", (pa + i) -> rno);
		printf("\nName\t: %s", (pa + i) -> name);
		printf("CGPA\t: %f\n", (pa + i) -> cgpa);
	}
	printf("\n");
}