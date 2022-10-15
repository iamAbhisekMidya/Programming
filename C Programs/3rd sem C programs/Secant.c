//Solve by Secant method [ 2x-log10(x)-7=0 ]

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float f(float x)
{
	return(2*x-log10(x)-7.0);
}
int main()
{
	float a,b,x,y,h,err;
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
	printf("\nEnter the correction upto decimal place: ");
  	scanf("%d",&d);
  	err=(5.0/pow(10,d));
  	x=0;
  	printf("\n\n  N\tXn(+ve) \t  Hn\t\tXn+1(A+Hn)\n");
  	printf("\n--------------------------------------------------\n");
    do
  	{
		y=x;
		h=-(f(a)/(f(b)-f(a)))*(b-a);
		x=a+h;
		printf("\n %2d \t%2.5f \t%+2.5f \t %+2.5f\n",++n,y,h,x);
		b=x;
   	}while(fabs(x-y)>=err);
  	printf("\n\n\t  The root is: x=%f\n\n\n",x);
	return 1;
}



