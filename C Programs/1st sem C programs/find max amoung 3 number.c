#include<stdio.h>
int main()
{
	int a,b,c,max;
	printf("Enter the first number: ");
	scanf("%d",&a);
	printf("Enter the secound number: ");
	scanf("%d",&b);
	printf("Enter the third number: ");
	scanf("%d",&c);
	max=a;
	if(a>b)
	{
		if(a>c)
			max=a;
		else
			max=c;
	}
	else
	{
		if(b>c)
			max=b;
		else
			max=c;
	}
	printf("\nThe maximum number is %d amoung the three numbers %d,%d,%d.\n",max,a,b,c);
	return 1;
}
