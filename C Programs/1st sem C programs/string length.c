#include<stdio.h>
int strlen1(char *a)
{
	int i=0;
	while(a[i]!='\0')
	i++;
	return i;
}
int main()
{
	char a[100];
	int i;
	printf("Enter the string: ");
    gets(a);
    i=strlen1(a);
    printf("\nThe string lenth is %d\n",i);
    return 1;
}

