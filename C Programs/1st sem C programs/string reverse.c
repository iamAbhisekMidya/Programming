#include<stdio.h>
void strrev1(char *a)
{
	char t;
	int i,j;
	i=0;
	while(a[i]!='\0')
	{
		i++;
	}
	i--;
	j=0;
	while(i>=j)
	{
	
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		i--;
		j++;
    } 
}
int main()
{
	char a[100];
	int i=0;
	printf("Enter the string: ");
	gets(a);
	strrev1(a);
	printf("\nAfter reversing the string become: ");
	while(a[i]!='\0')
	{
		printf("%c",a[i]);
		i++;
	}
	return 1;
}

