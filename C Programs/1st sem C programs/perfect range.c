#include<stdio.h>
int main()
{
	int n,s,i,a,b;
	printf("Enter the upper limit of the range: ");
	scanf("%d",&a);
	printf("\nEnter the lower limit of the range: ");
	scanf("%d",&b);
    printf("\nPerfect numbers are: \n\n");
    for(n=a;n<=b;n++)
	{
		s=0;
		i=1;
		while(i<=n/2)
		{
			if(n%i==0)
				s=s+i;
			i=i+1;
		}
		if(s==n)
			printf("%d ",s);
	}
	return 1;
}

