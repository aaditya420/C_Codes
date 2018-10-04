#include "custom.h"
#define MAX 100

struct student 
{
	int rno;
	char n[MAX];
	double m;
	struct student *next;
};

typedef struct student node;

node *start = NULL, *temp, *current = NULL;

void push()
{
	temp = (node *)malloc(sizeof(node));
	
	printf("\nEnter Details\t:\t\n\n");
	printf("Roll No.:\t");
	scanf("%d", &temp -> rno);
	printf("Name    :\t");
	scanf("%s[^\n]", temp -> n);
	printf("Marks   :\t");
	scanf("%lf", &temp -> m);
	
	if(start == NULL)
	{
		start = temp;
		current = temp;
	}	
	else
	{
		current -> next = temp;
		current = temp;
		current -> next = NULL;
	}
}

void pop()
{
	if(start == NULL)
	{
		printf("\nNo elements found!\n");
		return;
	}
	else
	{
		temp = start -> next;
		start = temp;
	}
}

void display()
{
	if(start == NULL)
	{
		printf("\nNo records found!\n");
		return;
	}
	int i = 1;
	temp = start;
	while(temp != NULL)
	{
		printf("\nRecord\t%d\t\n", i);
		printf("Roll No. :\t%d\n", temp -> rno);
		printf("Name     :\t%s\n", temp -> n);
		printf("Marks    :\t%lf\n", temp -> m);
		temp = temp -> next;
		i++;
	}
}

void search()
{
	int r, f = 0;
	printf("\nEnter Roll No. to search for : ");
	scanf("%d", &r);
	temp = start;
	while(temp != NULL)
	{
		if(temp -> rno == r)
		{
			printf("\nRecord found!\n");
			printf("Roll No. :\t%d\n", temp -> rno);
			printf("Name     :\t%s\n", temp -> n);
			printf("Marks    :\t%lf\n", temp -> m);
			f = 1;
			break;
		}
		temp = temp -> next;
	}
	if(f == 0)
		printf("\nRecord not found!\n");
}

int main()
{
	char ch = ' ', ch1;
	do
	{
		printf("\n\n\tMAIN_MENU\n");
		printf("\n1.Push\n");
		printf("\n2.Pop\n");
		printf("\n3.Display\n");
		printf("\n4.Search\n");
		printf("\n5.Exit");
		printf("\n\nEnter choice...");
		if(ch != ' ')
			ch1 = getchar();
		scanf("%c", &ch);
		if(ch == '1')
		{
			push();
		}
		else if(ch == '2')
		{
			pop();
		}
		else if(ch == '3')
		{
			display();
		}
		else if(ch == '4')
		{
			search();
		}
		else if(ch == '5')
		{
			exit(0);
		}
		else 
			printf("\nINVALID CHOICE!!!\n");
	}while(ch != '5');
}
