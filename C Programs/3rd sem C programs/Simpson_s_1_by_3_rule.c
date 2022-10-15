//FOR  Intregration [e^(atan(x))]
#include<stdio.h>
#include<math.h>
double f(double x)
{
    return (exp(atan(x)));
}
int main()
{
	double a,b,x[50],y[50],h,sum0=0.0,sum1=0.0,sum2=0.0;
	int n,i;
	printf("Enter the lower limit: ");
	scanf("%lf",&a);
	printf("\nEnter the upper limit: ");
	scanf("%lf",&b);
	printf("\nEnter the number of sub intervals: ");
	scanf("%d",&n);
	if (n%2!=0)
	{
		printf("\nThe number of sub-intervals should be even.\n");
	 	return 0;
	}
	h=(b-a)/n;
	x[0]=a;
	x[n]=b;
	y[0]=f(x[0]);
	y[n]=f(x[n]);
	sum0=y[0]+y[n];
	for(i=1;i<n;i+=2)
	{	
		x[i]=x[0]+i*h;
	 	y[i]=f(x[i]);
	 	sum1=sum1+y[i];
	}
	for(i=2;i<n;i+=2)
	{ 
		x[i]=x[0]+i*h;
		y[i]=f(x[i]);
		sum2=sum2+y[i];
	}
	//Steps display [optional]
	printf("\nComputation table:-\n");
	printf("\n|  i  |\t| Xi=Xo+ih |\t| Yi=f(x),i=0,%d |\t|Yi=f(x),i=1,3,..|\t|Yi=f(x),i=2,4,..|\n\n",n);
	for(i=0;i<=n;i++)
	{
		printf("| %2d  |\t|   %3.2lf   |",i,x[i]);
		if(i==0||i==n)
			printf("\t|     %3.5lf\t |",y[i]);
		else
			printf("\t|\t\t |");
		if(i==0||i==n)
		{
			printf("\t|\t\t |\t|\t\t |\n");
			continue;
		}
		if(i%2==0)
			printf("\t|\t\t |\t|     %5.5lf\t |\n",y[i]);
		else
			printf("\t|     %5.5lf\t |\t|\t\t |\n",y[i]);	
	}
	printf("\n| sum |\t| \t   |\t|     %5.5f\t |\t|     %5.5lf\t |\t|     %5.5lf\t |\n",sum0,sum1,sum2);
	//step display stop.
	sum1=(h/3.0)*(sum0+(4*sum1)+(2*sum2));
	printf("\n\nThe result is = %5.5lf\n",sum1);
	return 1;
}
