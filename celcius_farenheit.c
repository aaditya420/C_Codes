#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ARG 1
#define MAX 100

void celcius(float *f)
{
	*f = (5.0 / 9.0) * (*f - 32.0);
}

void ft(float *c)
{
	printf("\n%f\n", *c);
	*c = ((9.0 / 5.0) * *c) + 32.0;
}

int main(int v, char * arg[])
{
	if(v != MAX_ARG)
	{
		printf("error : invalid arguments\n");
		return -1;
	}

	float t;
	int ch;

	printf("\nEnter temperature : ");
	scanf("%f", &t);

	printf("\n\nConvert to : \n\n");
	printf("1.Celcius\n");
	printf("2.Farenheit\n");

	scanf("%d", &ch);

	if(ch == 1)
	{
		celcius(&t);
		printf("\nConverted to celcius : %f\n", t);
		return 0;
	}
	if(ch == 2)
	{
		ft(&t);
		printf("\nConverted to farenheit : %f\n", t);
		return 0;
	}
	if(ch > 2)
	{
		printf("\nerror : invalid choice\n");
		return -1;
	}
}
