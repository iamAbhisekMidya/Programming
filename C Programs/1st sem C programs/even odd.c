#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	if(n%2==0)
		printf("Enter number %d is even number\n",n);
	else
		printf("Enter number %d is odd number\n",n);	
	return 1;	
}
