#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void string_sort(char*a[],int n)         
{
	int i,j,min,c,s;
	char t[50];
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			s=strcmp(a[i],a[j]);
			if(s>0)
			{
				strcpy(t,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],t);
			}
		}
	}
	printf("string after sort\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
	}
}
int main()
{
	char *a[50];
	int i,n;
	printf("how many string you want to insert ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	  a[i]=(char *)malloc(sizeof(char)*50);
	  printf("enter the string[%d]= ",i+1);
	  fflush(stdin);
	  gets(a[i]);
	}
	string_sort(a,n);
	return 1;
}
