#include<stdio.h>
int main()
{
	int binary_search(int *,int ,int ,int );
	int a[50],n,i,x,pos;
	printf("How many numbers you want to insert: ");
	scanf("%d",&n);
	printf("\nEnter numbers in [ASSENDING ORDER] \n\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the value which you want to search: ");
	scanf("%d",&x);
	pos=binary_search(a,0,n-1,x);
	if(pos==-1)
		printf("\nEntered value %d is not found\n",x);
	else
		printf("\nEntered value %d is found at %d possition\n",x,pos+1);
	return 1;		
}
int binary_search(int a[50],int low,int high,int x)
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x==a[mid])
			return mid;
		if(x<a[mid])
			high=mid-1;
		else
			low=mid+1;					
	}
	return -1;
}
