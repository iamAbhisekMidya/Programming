#include<stdio.h>
int main()
{
	int n,s,i;
	printf("Enter the number: ");
	scanf("%d",&n);
	s=0;
	i=1;
	while(i<=n/2)
	{
		if(n%i==0)
			s=s+i;
		i++;
	}
	if(s==n)
		printf("\nThe entered number is a perfect number.\n");
	else
		printf("\nThe entered number is not a perfect number.\n");
	return 1;
}

