#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x)
{
	return(x*x*x-3*x+1.06);
}
int main()
{
	float a,b,x,y,err;
	int n=0,d;
	printf("Enter the lower limit: ");
	scanf("%f",&a);
	printf("\nEnter the upper limit: ");
	scanf("%f",&b);
	if(f(a)*f(b)>0)
	{
		printf("\nRoot does not exists between %f and %f\n",a,b);
		exit(0);
	}
	// We consider "f(a)" as (+ve) and "f(b)" as (-ve)
	if(f(a)<0&&f(b)>0)   //swap the values of a and b.
	{
		y=b;
		b=a;
		a=y;
	}
	printf("\nEnter the correction upto decimal place: ");
  	scanf("%d",&d);
  	err=(5.0/pow(10,d));
  	printf("\n\n  N\tAn(+ve) \tBn(-ve) \tXn+1(An+Bn)/2 \tf(Xn+1)\n");
	printf("\n----------------------------------------------------------------\n");
	//Consider the initial root is 0  
	x=0;
	do
	{
		y=x;
		x=(a+b)/2;
		printf("\n %2d \t%2.5f \t%2.5f \t%2.5f \t%+2.5f\n",++n,a,b,x,f(x));
		if(f(x)>0)
			a=x;
		else
			b=x;
	}while(fabs(x-y)>=err);
	printf("\n\n\t\t\tThe root is: x=%f\n\n\n",x);
	return 1;
}
