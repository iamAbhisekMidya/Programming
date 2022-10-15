#include<stdio.h>
int main()
{
	int i,j,k,x,y,z,n;
	printf("Enter the rows: ");
	scanf("%d",&n);
	printf("\n");
	for(z=n;z>0;z--)
	{
		for(x=z;x<=n;x++)
		{
			printf(" ");
		}
		for(y=(2*z)-1;y>0;y--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 1;
}
