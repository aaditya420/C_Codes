#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100
#define MAX_S 100

int main()
{

    char s[MAX], arr[MAX], t[MAX];
    int i, n, ls, x, k, l, j;
    int count  = 0;
    
    scanf("%s", s);
    scanf("%d", &n);
    
    ls = strlen(s);    
    
    for(i = 0 ; i < n ; i++)
    {
            scanf("%s", arr);

            if(strlen(arr) - 1 == ls)
            {
                for(k = 0, x = 0 ; k < strlen(arr) ; x++)
                    if(k != j)
                        t[k++] = arr[x];

                if(strcmp(s, t) == 0)
                    count++;
                printf("%d\n", count);
            }

            else if(strlen(arr) + 1 == ls)
            {
                strcpy(t, arr);
                for(k = 0 ; k < strlen(t) ; k++)
                {
                    for(x = 0 ; x < ls ; x++)
                    {
                        for(l = strlen(t) ; l > k ; l--)
                            t[l] = t[l - 1];

                        t[k] = s[x];
                        if(strcmp(t, s) == 0)
                            count++;
                        printf("%d\n", count);
                    }
                }
            }
    }
    printf("%d", count);
    return 0;
}


