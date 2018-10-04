#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct emp
{
	int id;
	char name[MAX];
}E;

int main(int v, char * arg[])
{
	if(v != 2)
	{
		printf("invalid arguments\n");
		return -1;
	}

	FILE *f = fopen("employee.txt", "w");
	E e;

	int n = atoi(arg[1]), i;
	for(i = 0 ; i < n ; i++)
	{
		printf("\nEnter employee %d id   : ", i + 1);
		scanf("%d", &e.id);
		printf("\nEnter employee %d name : ", i + 1);
		scanf("%s", e.name);

		fwrite(&e, sizeof(E), 1, f);
	}
	fclose(f);

	f = fopen("employee.txt", "r");
	if(f == NULL)
	{
		printf("\nERROR OPENING FILE\n");
		return -1;
	}

	int i_id = 1;
	while(i_id != 0)
	{
		printf("\nEnter employee id to search : ");
		scanf("%d", &i_id);

		if(i_id == 0)
			break;

		int flag = 0;
		while(!feof(f))
		{
			fread(&e, sizeof(E), 1, f);
			if(feof(f))
				break;
			if(e.id == i_id)
			{
				flag = 1;
				break;
			}
		}
		rewind(f);
		if(flag == 1)
		{
			printf("\nEmployee found :\n");
			printf("\nEmployee id   : %d\n", e.id);
			printf("\nEmployee name : %s\n", e.name);
		}
		else
			printf("\nEmployee not found!\n");
	}

}