//Solve by Newton Raphson method [ X^3-3X^2+2X-5=0 ]

#include<stdio.h>
#include<math.h>
float f(float x)
{
	return(pow(x,3)-3*x*x+2*x-5);
}
float fd(float x)
{
	return(3*pow(x,2)-6*x+2);
}
float fdd(float x)
{
	return(6*x-6);
}
int main()
{
	float h,x,y,err;
	int n=0,d;
 	do
  	{
		printf("Enter an approximate root: ");
		scanf("%f",&x);
		if(fabs(f(x)*fdd(x))<(fd(x)*fd(x)))
			break;
		else
			printf("\nWrong value entered!!!try again...\n");
	}while(1);
	printf("\nEnter the correction upto decimal place: ");
  	scanf("%d",&d);
  	err=(5.0/pow(10,d));
  	printf("\nIter\t   Xn\t\t  f(Xn)\t\t  f'(Xn)\t   Hn\t\tXn+1=Xn+Hn\n");
	printf("----------------------------------------------------------------------------------\n");
	y=x;
	h=f(x)/fd(x);
	x=x-h;
	printf(" %2d\t%+f\t%+f\t%+f\t%+f\t%+f\n",++n,y,f(y),fd(y),h,x);
	while(fabs(x-y)>=err)
	{
		y=x;
		h=f(x)/fd(x);
		x=x-h;
		printf(" %2d\t%+f\t%+f\t%+f\t%+f\t%+f\n",++n,y,f(y),fd(y),h,x);
	}
	printf("\n\nThe root is: %f",x);
 	return 1;
}	
