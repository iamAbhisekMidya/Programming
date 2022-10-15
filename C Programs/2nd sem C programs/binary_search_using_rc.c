#include<stdio.h>
int main()
{
	int binary_search_rc(int *,int ,int ,int );
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
	pos=binary_search_rc(a,0,n-1,x);
	if(pos==-1)
		printf("\nEntered value %d is not found.\n",x);
	else
		printf("\nEntered value %d is found at %d possition.\n",x,pos+1);
	return 1;		
}
int binary_search_rc(int a[50],int low,int high,int x)
{
	int mid;
	if(low>high)
		return -1;
	mid=(low+high)/2;
	if(x==a[mid])
		return mid;
	if(x<a[mid])
		binary_search_rc(a,low,mid-1,x);
	else
		binary_search_rc(a,mid+1,high,x);					
}
