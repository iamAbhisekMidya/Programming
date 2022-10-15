#include<stdio.h>
int main()
{
	int a[100],r,n,i;
	printf("Enter the number: ");
	scanf("%d",&n);
	i=0;
	while(n!=0)
	{
		i++;
		r=n%2;
		a[i]=r;
		n=n/2;
	}
	printf("\nThe binary number is: ");
	while(i!=0)
	{
		printf("%d",a[i]);
		i--;
	}
	return 1;
}
