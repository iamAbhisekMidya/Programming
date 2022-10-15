#include<stdio.h>
int main()
{
	int linear_search(int [],int ,int );
	int a[100],n,i,x,pos;
	printf("How many numbers you want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the value which you want to search: ");
	scanf("%d",&x);
	pos=linear_search(a,n,x);
	if(pos==-1)
		printf("\nEntered value %d is not found.\n",x);
	else
		printf("\nEntered value %d is found at %d possition.\n",x,pos+1);
	return 1;
}
int linear_search(int a[],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
			return i;
	}
	return (-1);
}
