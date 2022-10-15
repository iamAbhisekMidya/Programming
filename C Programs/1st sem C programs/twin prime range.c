#include<stdio.h>
int check_prime(int n)
{
	int i;
	if(n<2)
		return 0;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}
int main()
{
	int i,a,b;
	printf("Enter the lower bound: ");
    scanf("%d",&a);
    printf("\nEnter the upper bound: ");
    scanf("%d",&b);
    printf("\nTwin prime numbers are:\n\n");
	for(i=a;i<=b;i++)
	{
		if(check_prime(i)&&check_prime(i+2))
		printf("(%d,%d) ",i,i+2);
	}
	return 1;
}
