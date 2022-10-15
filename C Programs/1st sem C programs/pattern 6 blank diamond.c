#include<stdio.h>
int main()
{
	int i,j,k,x,y,z,n;
	printf("Enter the number of rows: ");
	scanf("%d",&n);
	printf("\n");
	for(j=1;j<=(n/2)+1;j++)
		printf(" ");
	printf("*\n");	
	for(i=1;i<(n/2);i++)
	{
		for(j=i;j<=(n/2);j++)
		{
			printf(" ");
		}
		printf("*");
		for(k=1;k<=2*i-1;k++)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	for(z=(n/2);z>0;z--)
	{
		for(x=z;x<=n/2;x++)
		{
			printf(" ");
		}
		printf("*");
		for(y=(2*z)-1;y>0;y--)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	for(j=1;j<=(n/2)+1;j++)
		printf(" ");
	printf("*\n");
	return 1;
}
