#include<stdio.h>
int main()
{
	int i,j,k,x,y,z,n;
	printf("Enter the number of rows: ");
	scanf("%d",&n);
	printf("\n");
	if(n%2!=0)
	n=n+1;
	for(i=1;i<=(n/2);i++)
	{
		for(j=i;j<=(n/2);j++)
		{
			printf(" ");
		}
		for(k=1;k<=2*i-1;k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(z=(n/2)-1;z>0;z--)
	{
		for(x=z;x<=n/2;x++)
		{
			printf(" ");
		}
		for(y=(2*z)-1;y>0;y--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 1;
}
