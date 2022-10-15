#include<stdio.h>
#include<math.h>
int main()
{
	int n,z,r,s,i;
	printf("Enter the number: ");
	scanf("%d",&n);
    z=n;
	i=0;
	while(z!=0)
	{
		i++;
		z=z/10;
	}
	z=n;
	s=0;
	while(z!=0)	
	{
		r=z%10;
		s=s+pow(r,i);
		z=z/10;
		
	}
	if(s==n)
		printf("\nThe enter number %d is an armstrong number\n",n);
	else
		printf("\nThe enter number %d is not an armstrong number\n",n);
    return 1;
	}
