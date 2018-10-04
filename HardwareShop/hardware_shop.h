#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 	100
#define ITEM 	"item.dat"
#define CRED 	"credentials.dat"

typedef struct product
{
	int 	id;
	char 	name[MAX];
	float 	price
	int 	qty;
}PDT;

typedef struct customer
{
	char 		name[MAX];
	char 		addr[MAX]; 
	long int 	phno;
}CST;

void admin()
{
	FILE *f = fopen(CRED, "rb");

	if(f == NULL)
	{
		printf("\nFile %s not found!\n", CRED);
		break;
	}

	char uname[MAX], uname_i[MAX];
	char pass[MAX], pass_i[MAX];

	fgets(uname, MAX, f);
	fgets(pass, MAX, f);

	printf("\nLogin : \n");

	printf("\nUser Name : ");
	fgets(uname_i, MAX, stdin);

	printf("\nPassword : ");
	fgets(pass_i, MAX, f);
	fclose(f);

	if(strcmp(uname, uname_i) == 0 && strcmp(pass, pass_i) == 0)
	{
		printf("\nSuccessful Login!\n");
		char ch;
		do
		{
			printf("\n_______________________________________________\n");
			printf("\n\t\t\tADMIN\n");
			printf("_______________________________________________\n");
			printf("\n1.Store Item\n");
			printf("\n2.Remove Item\n");
			printf("\n3.Modify Item\n");
			printf("\n4.Display Items\n");
			printf("\n5.Logout\n");
			ch = getchar();
			if(ch == '1')
			{
				FILE *f = fopen(ITEM, "ab");
				PDT p;
				do
				{
					printf("\nEnter the product details : \n");
					printf("\nID    : ");
					scanf("%d", &p.id);
					if(p.id == 0)
						break;
					printf("\nName  : ");
					scanf("%s", p.name);
					printf("\nPrice : ");
					scanf("%f", &p.price);
					printf("\nQuantity : ");
					scanf("%d", &p.qty);
					fwrite(&p, sizeof(PDT), 1, f);
				}
				while(p.id != 0);
				fclose(f);
			}
			else if(ch == '2')
			{
				FILE *f = fopen(ITEM, "r+b");
				if(f == NULL)
				{
					printf("\nError opening %s\n", ITEM);
					break;
				}

				PDT p[MAX];
				int f = 0, n = 0, i, pid, j;
				fseek(f, 0, SEEK_END);
				n = ftell(f) / sizeof(PDT);
				rewind(f);

				fread(p, sizeof(PDT), n, f);

				printf("\nEnter the product id to remove : ");
				scanf("%d", &pid);

				for(i = 0 ; i < n ; i++)
				{
					if(p[i].id == pid)
					{
						f = 1;
						char ch;
						printf("\nRecord found!\n");
						printf("\nRemove the record or decrease qty? <1 or 2> : ");
						ch = getchar();
						if(ch == '1')
						{
							for(j = i ; j <= n ; j++)
								p[j] = p[j + 1];
							n--;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
						}
						if(ch == '2')
						{
							int val;
							printf("\nEnter the value to be decreased : ");
							scanf("%d", &val);
							if(val > p[i].qty)
							{
								f = 0;
								printf("\nINVALID INPUT\n");
								break;
							}
							p[i].qty -= val;
						}
						break;
					}
				}
				if(f == 0)
				{
					printf("\nUnsuccessful Operation!\n");
					fclose(f);
				}
				else
				{
					fwrite(p, sizeof(PDT), n, f);
					fclose(f);
				}
			}
			else if(ch == '3')
			{
				FILE *f = fopen(ITEM, "r+b");
				if(f == NULL)
				{
					printf("\nFile not found!\n");
					break;
				}
				PDT p[MAX];
				int n, pid, i, f = 0;
				fseek(f, 0, SEEK_END);
				n = ftell(f) / sizeof(PDT);
				rewind(f);

				fread(p, sizeof(PDT), n, f);
				
				printf("\nEnter the product id to modify : ");
				scanf("%d", &pid);
				for(i = 0 ; i < n ; i++)
				{
					if(p[i].id == pid)
					{
						f = 1;
						printf("\nRecord Found!\n");
						printf("\nEnter the modified details\n");
						printf("\nID 		: ");
						scanf("%d", p[i].id);
						printf("\nName  	: ");
						scanf("%s", p[i].name);
						printf("\nPrice 	: ");
						scanf("%f", &p[i].price);
						printf("\nQuantity 	: ");
						scanf("%d", &p[i].qty);
						break;
					}
				}
				if(f == 1)
				{
					printf("\nRecord modified successfuly!\n");
					fwrite(p, sizeof(PDT), n, f);
					fclose(f);
				}
			}
			else if(ch == '4')
			{
				FILE *f = fopen(ITEM, "rb");
				if(f == NULL)
				{
					printf("\nFILE NOT FOUND!\n");
					break;
				}
				PDT p[MAX];
				int n, i;
				fseek(f, 0, SEEK_END);
				n = ftell(f) / sizeof(PDT);
				rewind(f);

				fread(p, sizeof(PDT), n, f);

				for(i = 0 ; i < n ; i++)
				{
					printf("\n");
				}
			}
		}
		while(ch != '5');
	}
}

void menu()
{
	char ch;
	do
	{
		printf("\n_______________________________________________\n");
		printf("\n\t\t\tWELCOME\n");
		printf("_______________________________________________\n");
		printf("\n1.Admin\n");
		printf("\n2.Buy\n");
		printf("\n3.Exit\n");
		ch = getchar();
		switch(ch)
		{
			case '1' :	admin();
						break;
			case '2' :	buy();
						break;
			case '3' :	exit(0);
			default  :	printf("\nInvalid Choice!\n");
						break;
		}
	}
	while(ch != '3');
}