#include<stdio.h>
int main()
{
	int i,n,s=0,j=1;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s=s+(i*j);
		j=(j*(-1));
	}
	printf("Answer is => %d",s);
	return 1;
}
