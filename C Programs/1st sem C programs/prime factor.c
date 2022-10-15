#include<stdio.h>
int prime(int n)
{
	int i;
	if(n<2)
		return 0;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}
int pfactor(int a[],int n)
{
	int i,j,c=-1;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			j=prime(i);
			if(j==1)
			{
				c++;
				a[c]=i;
			}
		}
	}
	return c;
}
int main()
{
	int a[100],i,c,n;
	printf("Enter the number: ");
	scanf("%d",&n);
	c=pfactor(a,n);
	if(c==-1)
		printf("\nThere are no prime factor of this number %d\n",n);
	else
	{
		printf("\nThe prime factors of the given number are: ");
		for(i=0;i<=c;i++)
		{	
			printf("%d ",a[i]);
		}
	}
	return 1;
}
