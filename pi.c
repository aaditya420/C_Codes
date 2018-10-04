#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100000
#define PI 3.141592653589793

int main(int v, char * arg[])
{
	if(v != 4)
	{
		printf("\nERROR : INVALID ARGUMENTS!\n");
		return -1;
	}

	int r[MAX], n, a, b, i, c, tc = 0, j;
	double x, ep, pi;

	srand(time(NULL));

	n = atoi(arg[1]);
	a = atoi(arg[2]);
	b = atoi(arg[3]);

	for(i = 0 ; i < n ; i++)
		r[i] = (rand() % b) + a;

	for(i = 0 ; i < n ; i++)
		printf("\n%d", r[i]);

	for(i = 0 ; i < n ; i += 2)
	{
		if(r[i] > r[i + 1])
		{
			c = 0;
			for(j = 1 ; j < r[i] ; j++)
				if(r[i] % j == 0 && r[i + 1] % j == 0)
					c++;

			printf("\nc = %d", c);

			if(c == 1)
				tc++;
		}
		else
		{
			c = 0;
                        for(j = 1 ; j < r[i + 1] ; j++)
                        	if(r[i] % j == 0 && r[i + 1] % j == 0)
                        		c++;

                        printf("\nc = %d", c);

                        if(c == 1)
	                        tc++;	                                                                                                                                                                                tc++;
		}
	}
	printf("\ntc = %d\n", tc);

	x = (double)tc / ((double)n);
	printf("\nx = %lf\n", x);
	pi = sqrt(6 / x);
        ep = 100 * ((pi - PI) / PI);

	printf("\nCalculated PI  = %lf\n", pi);
	printf("\n\nError          = %lf%\n\n", ep);
}
