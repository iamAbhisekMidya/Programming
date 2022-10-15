//Solve by Runge Kutta 4th order method dy/dx=(1+x^2)y where y(0)=1 and x=0(0.2)0.6
#include<stdio.h>
#include<math.h>
float f(float x,float y)
{
	return ((1+pow(x,2))*y);
}
int main()
{
	float x,y,p,q,xf,h,d1,d2,d3,d4;
	int i=0;
	printf("Enter the initial value of x : ");
	scanf("%f",&x);
	printf("\nEnter the initial value of y : ");
	scanf("%f",&y);
	printf("\nEnter the final value of x : ");
	scanf("%f",&xf);
	printf("\nEnter the value of step length (h) : ");
	scanf("%f",&h);
	printf("\n\n Ite\t   Xi\t\t   Yi\t\t   D1\t\t   D2\t\t   D3\t\t   D4\t\t  Yi+1\n");
	printf("--------------------------------------------------------");
	printf("--------------------------------------------------------");
	while(x<xf)
	{
		d1=h*f(x,y);
		d2=h*f(x+h/2,y+d1/2);
		d3=h*f(x+h/2,y+d2/2);
		d4=h*f(x+h,y+d3);
		p=x;
		q=y;
		x=x+h;
		y=y+(1.0/6.0)*(d1+2*d2+2*d3+d4);
		printf("\n%3d\t%f\t%f\t%f\t%f\t%f\t%f\t%f",i++,p,q,d1,d2,d3,d4,y);
	}
	printf("\n\n\n\t\t\t   The result of Y(%.3f) = %f\n",x,y);
	return 1;
}
