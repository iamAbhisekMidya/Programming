#include<stdio.h>
#include<math.h>
int main()
{
	float x,sum,err,f=1,p,n;
	int k=3,i,j=-1;
	printf("Enter error: ");
	scanf("%f",&err);
	printf("\nEnter the value of x in degree : ");
	scanf("%f",&x);
	x=(3.145/180)*x;
	sum=x;
	p=x;
	n=pow(x,3)/6.0;
	f=6.0;
	while(fabs(n-p)>=err)
	{
		p=n;
		sum=sum+(p*j);
		k=k+2;
		f=f*(k-1)*k;
		n=pow(x,k)/f;
		j=j*(-1);
	}
	printf("\nThe sum is %.2f\n",sum);
	return 1;
}
