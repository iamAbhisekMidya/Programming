#include<stdio.h>
#include<stdlib.h>
void concat(char p[100],char q[100])
{
	int i=0,j=0;
	while(p[i]!='\0')
	i++;
	p[i]=32;
	i++;
	while(q[j]!='\0')
	{
		p[i++]=q[j++];
	}
	p[i]='\0';
}
int main()
{
	int i=0;
	char a[100],b[100];
	printf("Enter the string: ");
	gets(a);
	printf("Enter the string: ");
	fflush(stdin);
	gets(b);
	concat(a,b);
	printf("\nThe string become: \n\n")
	while(a[i]!='\0')
	{
		printf("%c",a[i]);
		i++;
	}
	return 1;
}
