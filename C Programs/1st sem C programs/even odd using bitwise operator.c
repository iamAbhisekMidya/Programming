#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	if((n&1)!=0)
		printf("Entered number %d is a odd number\n",n);
	else
		printf("Entered number %d is an even number\n",n);	
	return 1;
}
