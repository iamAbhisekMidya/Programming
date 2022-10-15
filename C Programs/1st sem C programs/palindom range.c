#include<stdio.h>
int main()
{
	int n,z,r,s,a,b;
	printf("Enter the upper limit of the range: ");
	scanf("%d",&a);
	printf("\nEnter the lower limit of the range: ");
	scanf("%d",&b);
    printf("\nPalindom numbers are: \n\n");
    for(n=a;n<=b;n++)
    {
		s=0;
		z=n;
		while(z!=0)	
		{
			r=z%10;
			s=(s*10 )+r;
			z=z/10;	
		}
		if(s==n)
			printf("%d ",s);
	}
    return 1;
}
