#include<stdio.h>
int main()
{
	int n,z,r,s,i,f;
	printf("Enter the number: ");
    scanf("%d",&n);
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
		printf("\nThe entered number is a krishnamurti number\n");
	else
    	printf("\nThe entered number is not a krishnamurti number\n");
    return 1;
}
