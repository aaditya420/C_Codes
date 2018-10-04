/*
	Program to take input distance in feet and convert 
	to meteres or vice-verca using pointers

	usage : ./ptr_struct_3 distance_1 distance_2 units(m/f)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct distance
{
	int d1;
	int d2;
}d;

int main(int v, char * arg[])
{
	if(v != 4)
	{
		printf("usage : ./ptr_struct_3 distance_1 distance_2 units(m/f)\n");
		return -1;
	}

	d f, m, *pf = &f, *pm = &m;

	if(arg[3][0] == 'm')
	{
		pm -> d1 = atoi(arg[1]);
		pm -> d2 = atoi(arg[2]);

		pf -> d1 = pm -> d1 / 0.3048;
		pf -> d2 = pm -> d2 / 2.54;

		printf("Converted to feet : %dft %din\n", pf -> d1, pf -> d2);
	//	1 m = 3.37 ft
	}
	else if(arg[3][0] == 'f')
	{
		pf -> d1 = atof(arg[1]);
		pf -> d2 = atof(arg[2]);

		pm -> d1 = pf -> d1 * 0.3048;
		pm -> d2 = pf -> d2 * 2.54;

		printf("Converted to meteres : %dm %dcm\n", pm -> d1, pm -> d2);
	}

}

