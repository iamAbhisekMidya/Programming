#include<stdio.h>
int gcd(int x,int y)
{
	if(x%y==0)
		return y;
	else
		gcd(y,x%y);
}
int main()
{
	int x,y,g,l;
	printf("Enter the first number: ");
    scanf("%d",&x);
    printf("\nEnter the secound number: ");
    scanf("%d",&y);
	if(x>y)
		g=gcd(x,y);
	else
		g=gcd(y,x);
	l=(x*y)/g;
	printf("\nGcd of two numbers %d and %d is :%d\n",x,y,g);	
	printf("\nLcm of two numbers %d and %d is :%d\n",x,y,l);
	return 1;
}
