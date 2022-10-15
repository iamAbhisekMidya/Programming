#include<stdio.h>
int main()
{
    int n,j,i;
    printf("Enter the numbers of row: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=i;j<n;j++)
		{
			printf(" ");
		}
		for(j=1;j<2*i;j++)
		{
			printf("*");
 		}
		printf("\n");
	}
	return 1;
}
