#include<stdio.h>
int main()
{
	long int i,n,f=1;
	printf("Enter the number: ");
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
		f=f*i;
	printf("\nThe factorial of %ld is %ld\n",n,f);
	return 1;	
}
