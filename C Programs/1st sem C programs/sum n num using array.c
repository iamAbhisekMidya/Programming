#include<stdio.h>
int main()
{
	int a[100],s=0,n,i;
	printf("How many number you want to sum: ");
	scanf("%d",&n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d]= ",i+1);
		scanf("%d",&a[i]);
		s=s+a[i];
	}
	printf("\nThe sum is %d\n",s);
	return 1;
}
