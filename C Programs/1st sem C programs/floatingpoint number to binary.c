#include<stdio.h>
#include<math.h>
void exact_showbit(int x)
{
	int i,y,l;
	l=log10(x)/log10(2);
	for(i=l;i>=0;i--)
	{
		y=1<<i;
		if((x&y)!=0)
			printf("1");
		else
			printf("0");
	}
}
int main()
{
	float n,y;
	int x,i,r;
	printf("Enter the floating point number: ");
	scanf("%f",&n);
	printf("\nThe binary number of this floating point decimal number [%.2f] is: ",n);
	x=n;
	y=n-x;
	exact_showbit(x);
	printf(".");
	for(i=1;i<4;i++)
	{
		y=y*2;
		r=y;
		printf("%d",r);
	}
	return 1;
}
