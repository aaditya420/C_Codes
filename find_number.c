#include <stdio.h>

int main()
{
	int n = 100, x, y, z, t, n1 = 0;
	while(n < 1000)
	{
		t = n;
		x = t % 10;
		t /= 10;
		y = t % 10;
		t /= 10;
		z = t % 10;
		n1 = y*100 + y*10 + y;
	//	printf("\nx = %d\ty = %d\tz = %d\n", x, y, z);
		if((3 * n) == n1)
			printf("\nThe number is\t:\t%d\n", n);
		n++;
	}
}