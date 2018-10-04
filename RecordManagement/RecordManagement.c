#include <stdio.h>
#include <string.h>
#define MAX 100

struct c
{
	int id;
	char name[MAX];
};

void read(struct c n[], int x)
{
	FILE *f = fopen("r.txt", "w");	
	int i;
	for(i = 0 ; i < x ; i++)
	{
		printf("\nEnter id %d\t:\t", i + 1);		
		scanf("%d", &n[i].id);
		printf("\nEnter name %d\t:\t", i + 1);
		scanf("%s", n[i].name);
		fwrite(&n[i], sizeof(struct c), 1, f);
	}

	fclose(f);
}

void dp(struct c n[], int x)
{
	FILE *f = fopen("r.txt", "a+");	
	int i;
	printf("\n__________________________________\n");
	printf("\nID\t|\tNAME");
	printf("\n__________________________________\n");
		
	for(i = 0 ; i < x ; i++)
	{		
		fread(&n[i], sizeof(struct c), 1, f);		
		printf("\n%d\t|\t%s\n", n[i].id, n[i].name);
		printf("__________________________________\n");		
	}

	fclose(f);
}

void sort(struct c n[], int x)
{
	FILE *f = fopen("r.txt", "r+");	
	int i, ch, j;
	printf("\nUnsorted data\t:\t\n");
	dp(n, x);
	printf("\nSort by <1>ID or <2>NAME ? ");
	scanf("%d", &ch);
	printf("\n");
	for(i = 0 ; i < x ; i++)
		fread(&n[i], sizeof(struct c), 1, f);
	for(i = 0 ; i < x ; i++)
	{
		for(j = i ; j < x ; j++)
		{
			struct c t;
			if(ch == 1)
			{
				if(n[i].id > n[j].id)
				{
					t = n[i];
					n[i] = n[j];
					n[j] = t;
				}
			}	
			else if(ch == 2)
			{
				if(strcmp(n[i].name, n[j].name) > 0)
				{
					t = n[i];
					n[i] = n[j];
					n[j] = t;
				}
			}
		}
	}
	
	rewind(f);

	for(i = 0 ; i < x ; i++)
		fwrite(&n[i], sizeof(struct c), 1, f);
	
	fclose(f);
}

int main()
{
	struct c n[MAX];
	FILE *fx = fopen("x.txt", "r+");
	int ch, x = 0;
	do
	{
		printf("\n__________________________________\n");		
		printf("\n\tMAIN_MENU\n");
		printf("__________________________________\n");		
		printf("\n1.READ\n2.DISPLAY\n3.SORT\n4.EXIT\nPlease enter your choice...");
		scanf("%d", &ch);
		if(ch == 1)
		{
			printf("\nEnter the number of records\t:\t");
			scanf("%d", &x);
			fprintf(fx, "%d", x);
			fclose(fx);		
			read(n, x);
		}
		else if(ch == 2)
		{
			fscanf(fx, "%d", &x);
	//		printf("\nx = %d\n", x);
			fclose(fx);		
			dp(n, x);
		}
		else if(ch == 3)
		{
			fscanf(fx, "%d", &x);
			fclose(fx);
			sort(n, x);
		}

	}while(ch != 4);
}
