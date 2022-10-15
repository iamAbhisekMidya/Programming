#include<stdio.h>
void strcpy1(char p[100],char q[100])
{
	int i=0;
	while(q[i]!='\0')
	{
		p[i]=q[i];
		i++;
	}
	p[i]='\0';
}
int main()
{
	int i=0;
	char a[100],b[100];
	printf("Enter the string: ");
	gets(b);
	strcpy1(a,b);
	printf("\nThe string after copy is:\n\n")
	while(a[i]!='\0')
	{
		printf("%c",a[i]);
		i++;
	}
	return 1;
}
