#include<stdio.h>
int main()
{
	int i,j,k,n;
	printf("Enter the number of rows: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=2*i;j<=2*n;j++)
	    {
     	  	printf(" ");
	    }
		for(k=1;k<=2*i-1;k++)
	  	{
	  		printf("*");
  		}
	  	printf("\n");
	}
	return 1;
}
