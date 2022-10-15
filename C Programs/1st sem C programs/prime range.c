#include<stdio.h>
int main()
{
	int n,i,a,b;
	printf("Enter the upper limit of the range: ");
	scanf("%d",&a);
	printf("\nEnter the lower limit of the range: ");
	scanf("%d",&b);
    printf("\nPrime numbers are: \n\n");
    for(n=a;n<=b;n++)
	{
		for(i=2;i<=n/2;i++)
		{
			if(n%i==0)
				break;
		}
		if(i>n/2&&n>1)
			printf("%d ",n);
	}
	return 1;
}
