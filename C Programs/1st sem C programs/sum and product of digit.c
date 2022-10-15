#include<stdio.h>
int main()
{
	int n,r,z,p,s;
	p=1;
	s=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	z=n;
	while(z!=0)
  	{
	 	r=z%10;
	 	s=s+r;
	 	p=p*r;
	 	z=z/10;
	}	
	printf("\nThe sum of digit is => %d, the product of the digit is => %d",s,p);	
	return 1;	
}
