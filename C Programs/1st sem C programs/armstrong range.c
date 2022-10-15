#include<stdio.h>
#include<math.h>
int main()
{
	int n,z,r,s,i,a,b;
	printf("Enter the upper limit of the range: ");
	scanf("%d",&a);
	printf("\nEnter the lower limit of the range: ");
	scanf("%d",&b);
    printf("\nArmstrong numbers are: \n\n");
    for(n=a;n<=b;n++)
    {
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
		printf("%d ",n);
	}
	return 1;
}
