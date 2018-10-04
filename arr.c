#include <stdio.h>

int main()
{
int x[] = {1,2,3,4,5};
int *ptr,i ;
ptr = x;
for(i=0;i<5;i++)
    {
    printf("\nAddress : %u",&x[i]);
    printf("\nElement : %d",x[i]);
    printf("\nElement : %u",*(x+i));
    printf("\nElement : %d",i[x]);
    printf("\nElement : %d",*ptr);
    }  
} 
