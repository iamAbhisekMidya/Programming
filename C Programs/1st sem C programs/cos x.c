#include<stdio.h>
#include<math.h>
int main()
{
	float x,sum,f=1.0;
	int n,i,j=-1,k;
	printf("Enter the number of term: ");
	scanf("%d",&n);
	printf("Enter the value of x*: ");
	scanf("%f",&x);
	x=(3.14/180)*x;
	sum=1;
	for(i=2,k=2;i<=n;i++,k+=2)
	{
		f=f*(k-1)*k;
		sum=sum+(pow(x,k)/f)*j;
		j=j*(-1);
	}
	printf("sum=> %.2f",sum);
	return 1;
	
}
