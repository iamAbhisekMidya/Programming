#include<stdio.h>
#include<math.h>
int main()
{
	int x,i,y,l,c1=0,c2=0;
	printf("Enter the number: ");
	scanf("%d",&x);
	l=log10(x)/log10(2);
	for(i=l;i>=0;i--)
	{
		y=1<<i;
		if((x&y)!=0)
			c1++;
		else
			c2++;
	}
	printf("Number of [1] present in the binary number of given decimal number %d is: %d\n",x,c1);
	printf("Number of [0] present in the binary number of given decimal number %d is: %d\n",x,c2);
	return 1;
}
