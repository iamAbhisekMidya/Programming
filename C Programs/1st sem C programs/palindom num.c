#include<stdio.h>
int main()
{
	int n,z,r,s;
	printf("Enter the number: ");
    scanf("%d",&n);
 	s=0;
	z=n;
	while(z!=0)	
	{
		r=z%10;
		s=(s*10 )+r;
		z=z/10;
	}
	if(s==n)
		printf("\nThe number is a palindom number.\n");
	else
		printf("\nThe number is not a palindom number.\n");
    return 1;
}
