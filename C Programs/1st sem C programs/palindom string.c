#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],k[100];
	int y;
	printf("Enter the string: ");
	gets(str);
	strcpy(k,str);
	strrev(str);
    y=strcmp(str,k);
    if(y==0)
		printf("\nThe entered string is a palindom string.\n");
	else 
		printf("\nThe entered string is not a palindom string.\n");
	return 1;
}
