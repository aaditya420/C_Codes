#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct student
{
	int rno;
	char name[MAX];
	char addr[MAX];
}S;

int main(int v, char *arg[])
{
	if(v != 3)
	{
		printf("usage : ./binary_fio file_name number_of_elements\n");
		return -1;
	}

	S a[2];
	FILE *f = fopen(arg[1], "wb");
	
	int n = atoi(arg[2]), i;
	printf("\nEnter the records :\n");
	for(i = 0 ; i < n ; i++)
	{
		printf("\nEnter rno  : ");
		scanf("%d", &a[i].rno);
		
		printf("Enter name : ");
		scanf("%s", a[i].name);
		
		getchar();
		printf("Enter addr : ");
		fgets(a[i].addr, MAX, stdin);
		a[i].addr[strlen(a[i].addr) - 1] = '\0';

		fprintf(f, "%d\t%s\t%s\n", a[i].rno, a[i].name, a[i].addr);
		fprintf(f, "Hello_WORLD\n");
	}

	//fwrite(a, sizeof(S), 2, f);
	printf("\nRecords read successfuly...\n");
	fclose(f);

	f = fopen(arg[1], "rb");
	S b[2];
	
	printf("\n%ld\n", ftell(f));  
	
	//fread(b, sizeof(S), 2, f);
	
	printf("\n%ld\n", ftell(f));
	
	printf("\nThe contents of the file are : \n\n");
	printf("Rno\tName\t\tAddress\n");
	for(i = 0 ; i < 2 ; i++)
		printf("\n%d\t%s\t\t%s\n", b[i].rno, b[i].name, b[i].addr);

	
	fseek(f, -sizeof(S), SEEK_CUR);
	printf("\n%ld\n", ftell(f));

	fread(b, sizeof(S), 2, f);
	printf("\nRno\tName\t\tAddress\n");
	for(i = 0 ; i < 1 ; i++)
		printf("\n%d\t%s\t\t%s\n", b[i].rno, b[i].name, b[i].addr);
	fscanf(f, "Hello_WORLD\n");

	rewind(f);	

	fread(b, sizeof(S), 2, f);
	printf("\nRno\tName\t\tAddress\n");
	for(i = 0 ; i < 2 ; i++)
		printf("\n%d\t%s\t\t%s\n", b[i].rno, b[i].name, b[i].addr);
}