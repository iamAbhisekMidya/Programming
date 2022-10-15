#include<stdio.h>
#include<stdlib.h>
int strcmp1(char p[100],char q[100])
{
	int i;
	while(p[i]!='\0'&&q[i]!='\0')
	{
		if(p[i]!=q[i])
			return (p[i]-q[i]);
		i++;
	}
	return (p[i]-q[i]);
}
int main()
{
	int i;
	char a[100],b[100];
	printf("Enter 1st string: ");
	gets(a);
	printf("\nEnter 2nd string: ");
	fflush(stdin);
	gets(b);
	i=strcmp1(a,b);
	if(i==0)
		printf("\nThe two strings are equeal.\n");
	else
		printf("\nThe two string are not equeal and the difference between two strings is %d\n",i);
	return 1;
}
