#include<stdio.h>
int main()
{
	int n,i=0,r,x=0,y=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	while(n!=0)
	{
		i++;
		r=n%10;
		if(i%2==0)
			x=x+r;
		else 
			y=y+r;
		n=n/10;
	}
	if(x==y)
		printf("\nThe number is divisible by 11\n");
	else
		printf("\nThe number is not divisible by 11\n");
	return 1;
}
