#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

FILE *f;

typedef double d;

typedef struct salary
{
	d basic;
	d deduc;
	d tax;
	d fs;
}slry;

typedef struct emp
{
	int  eid;
	char nm[MAX];
	char desig[MAX];

	slry s;
}e;

e *ed;

int read_emp()
{
	if((f = fopen("emp.dat", "w")) == NULL)
	{
		ferror(f);
		return -1;
	}

	do
	{
//		printf("\nINSIDE DO WHILE\n");
		ed = (e *)malloc(sizeof(e));

		printf("\nEnter employee info (enter eid = 0 to exit) : \n\n");
		
		printf("\nEnter employee ID\t: ");
		scanf("%d", &ed -> eid);

		if(ed -> eid == 0)
			break;
		
		getchar();

		printf("\nEnter employee name\t: ");
		fgets(ed -> nm, MAX, stdin);
		
		printf("\nEnter employee designation\t: ");
		fgets(ed -> desig, MAX, stdin);

		printf("\nEnter basic pay\t: ");
		scanf("%lf", &ed -> s.basic);

		printf("\nEnter tax\t: ");
		scanf("%lf", &ed -> s.tax);

		printf("\nEnter deductions\t: ");
		scanf("%lf", &ed -> s.deduc);

		ed -> s.fs = ed -> s.basic - ed -> s.deduc - ((ed -> s.tax / 100) * ed -> s.basic);

		fprintfzs(f, "%d\t%s\b\t%s\b\t%lf\t%lf\t%lf\t%lf\n", ed -> eid, ed -> nm, ed -> desig, ed -> s.basic, ed -> s.tax, ed -> s.deduc, ed -> s.fs);

	}while(ed -> eid != 0);

	fclose(f);
	return 0;
}

int display_emp()
{
	if((f = fopen("emp.txt", "r+")) == NULL)
	{
		ferror(f);
		return -1;
	}

	printf("\nFILE_OPENED!");

	int i = 0;
	printf("\nEmployee details :\n\n");
	while(!feof(f))
	{
		if(feof(f))
			break;
		fscanf(f, "%d%s%s%lf", &ed -> eid, ed -> nm, ed -> desig, &ed -> s.fs);
		printf("\nEmployee %d :\n\n", i + 1);
		printf("\nEID\t: %d", ed -> eid);
		printf("\nName\t: %s", ed -> nm);
		printf("\nDesignation : %s", ed -> desig);
		printf("\nFinal Salary\t: %lf", ed -> s.fs);
	}
}

int menu()
{
	int ch;
	do
	{		
		printf("\nMAIN_MENU\n\n");
		printf("\n1.Read_Data\n");
		printf("\n2.Display_Data\n");
		printf("\n3.Exit\n");
	
		printf("\nEnter choice <1-3> : ");
		scanf("%d", &ch);
	//	printf("CHOICE ENTERED\n");
		if(ch == 1)
			read_emp();
		else if(ch == 2)
			display_emp();
		else
			exit(-1);

	}while(ch != 3);
}