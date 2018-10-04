#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 500

int main() {
 
    int t, i, x, k, f, o, l, j;
    long m, chksum = 0, count = 0;
    int num[MAX], temp[MAX];
    
    scanf("%d", &t);
    
    for(i = 0 ; i < t ; i++)
    {
        scanf("%d%ld", &x, &m);
        chksum = 0;

        for(j = 0 ; j < x ; j++)
            num[j] = 0;
    
        for(j = 0 ; j < x ; j++)
            temp[j] = 0;

        for(j = 0 ; j < x ; j++)
        {
            for(k = 0 ; k < x - j ; k++)
            {
                for(l = 0 ; l < 9 ; l++)
                    num[x - j - k]++;
                num[x - j - k] = 0;
                
            }
        }
    }
}