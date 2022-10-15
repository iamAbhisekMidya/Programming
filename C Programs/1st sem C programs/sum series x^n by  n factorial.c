#include<stdio.h>
#include<math.h>
int main()
{
	int x,i,n;
	float sum=0,f=1;
	printf("Enter the number: ");
	scanf("%d",&x);
	printf("How many term: ");
	scanf("%d",&n);
	sum=1;
	for(i=1;i<n;i++)
	{
		f=f*i;
		sum=sum+pow(x,i)/f;
	}
	printf("\nThe result is %.2f",sum);
	return 1;
}
