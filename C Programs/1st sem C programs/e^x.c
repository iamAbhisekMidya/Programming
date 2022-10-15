#include<stdio.h>
#include<math.h>
int main()
{
	float x,sum=1,f=1;
	int n,i;
	printf("Enter the value of x: ");
	scanf("%f",&x);
	printf("\nEnter the number of term: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		f=f*i;
		sum=sum+pow(x,i)/f;
	}
	printf("\nThe sum is %.2f\n",sum);
	return 1;
}
