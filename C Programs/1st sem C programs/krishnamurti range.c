#include<stdio.h>
int main()
{
	int n,z,r,s,a,b,i,f;
	printf("Enter the upper limit of the range: ");
	scanf("%d",&a);
	printf("\nEnter the lower limit of the range: ");
	scanf("%d",&b);
    printf("\nKrishnamurty numbers are: \n\n");
    for(n=a;n<=b;n++)
    {
		s=0;
		z=n;
		while(z!=0)	
		{
			r=z%10;
			f=1;
			z=z/10;
	       	for(i=1;i<=r;i++)
		 	{
		  		f=f*i;
	     	}
		   	s=s+f;
   		}
		if(n==s)
		{
			printf("%d ",n);
	    }
    }
    return 1;
}
