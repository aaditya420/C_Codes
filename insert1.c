#include <stdio.h>
#include <stdlib.h>
struct student 
{
	int roll;
	char name[15];
	struct student *link;
};
typedef struct student NODE;
void main()
{
	NODE *temp;
	NODE *start = NULL;
	NODE *current = NULL;
	int i,n;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	printf("Enter the details of students:\n");
	for(i=0;i<n;i++)
	{
		temp=(NODE *)malloc(sizeof(NODE));
		scanf("%d",&temp->roll);
		scanf("%s",temp->name);
		//temp->link=;
		current->link=temp;
		current=temp;
		current->link=NULL;
	}
	temp=start;
	do
	{
	  printf("%d \n %s\n",temp->roll,temp->name);
	  temp=temp->link;
	}while(temp->link!=NULL);
	/*printf("Enter the node to insert at beginning:\n");
	temp=(NODE *)malloc(sizeof(NODE));
	scanf("%d",&temp->roll);
	scanf("%s",temp->name);
	temp->link=temp;
	start=temp;*/
}

