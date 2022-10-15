#include<stdio.h>
int main()
{
	int n,r,z,s=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	z=n;
	while(z!=0)
	{
		r=z%10;
		s=(s*10)+r;
		z=z/10;
	}
	printf("The reverse number of the %d number is => %d",n,s);
	return 1;
}
