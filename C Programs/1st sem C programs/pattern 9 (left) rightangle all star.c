#include<stdio.h>
int main()
{
	int i,n,k;
	printf("Enter the number of rows: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(k=1;k<=i;k++)
	  	{
	  		printf("*");
  		}
	  	printf("\n");
    }
	return 1;
}
