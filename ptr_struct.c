/*
	Program to input details of student, calculate average and display details

	usage : ./ptr_struct roll_no name marks_1 marks_2 marks_3...
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct student
{
	int rno;
	char name[MAX];
	int marks[MAX];
	float mm;
	float p;
	float av;
}s;

int main(int v, char * arg[])
{
	int i = 4, j = 0;
	
	s ss, *ps = &ss;
	ps -> rno = atoi(arg[1]);
	ps -> mm = atoi(arg[3]);
	strcpy(ps -> name, arg[2]);

	ps -> av = 0;
	ps -> p  = 0;
	while(arg[i] != NULL)
	{
		ps -> marks[j] = atoi(arg[i]);
		ps -> av += ps -> marks[j];
		i++;
		j++;
	}	

	ps -> p = ((float)(ps -> av)/(float)(ps -> mm * j)) * 100.0; 

	printf("Entered details\t: \n");
	printf("Roll_No\t: %d\n", ps -> rno);
	printf("Name\t: %s\n", ps -> name);
	printf("Marks\t: ");
	
	for(i = 0 ; i < j ; i++)
		printf("%d ", ps -> marks[i]);

	printf("\nPercent\t: %.4f%\n", ps -> p);
}