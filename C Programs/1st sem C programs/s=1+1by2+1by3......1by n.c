#include<stdio.h>
int main()
{
	int n;
	float i=1.0,s=0.0;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	while(i<=n)
	{
		s=s+(i/(i+1));
		i=i+1;
	}
	printf("Sum is => %.2f",s);
	return 1;
}
