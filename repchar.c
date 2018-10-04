#include <stdio.h>

int main()
{
	int i;
	char str[50], *ptr, ch1, ch2;
	printf("\nEnter a string : ");
	scanf("%s", str);
	ptr = str;
	getchar();
	printf("\nEnter character to be replaced : ");
	scanf("%c", &ch1);
	printf("\nEnter character to be replaced with : ");
	scanf("%c", &ch2);
	scanf("%c", &ch2);
	for(i = 0 ; *(ptr + i) != '\0' ; i++)
		if(*(ptr + i) == ch1)
			*(ptr + i) = ch2;
	printf("%c %c", ch1, ch2);
	printf("\nUpdated string : %s\n", str);
}