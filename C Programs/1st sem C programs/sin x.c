#include<stdio.h>
#include<math.h>
int main()
{
	float x,sum,f=1;
	int n,i,j=-1,k;
	printf("Enter the value of x in degree (x*): ");
	scanf("%f",&x);
	printf("Enter the number of term: ");
	scanf("%d",&n);
	x=(3.14/180)*x;
	sum=x;
	for(i=2,k=3;i<=n;i++,k+=2)
	{
		f=f*(k-1)*k;
		sum=sum+(pow(x,k)/f)*j;
		j=j*(-1);
	}
	printf("\nThe sum is %.2f\n",sum);
	return 1;
}
