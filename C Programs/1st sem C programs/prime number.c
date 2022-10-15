#include<stdio.h>
int main()
{
	int n,i;
	printf("Enter the number: ");
	scanf("%d",&n);
	if(n<2)
	{
		printf("\n%d is not a prime number.\n",n);
	 	return 1;
	}
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
			break;
	}
	if(i>n/2)
		printf("\n%d is a prime number.\n",n);
	else
		printf("\n%d is not a prime number.\n",n);
 	return 1;
}
