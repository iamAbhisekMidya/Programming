#include<stdio.h>
int main()
{
	void insertion_sort(int *,int );
	int a[100],n,i,ch;
	printf("How many values you want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	insertion_sort(a,n);
	printf("\nThe array after insertion sort:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 1;	
}
void insertion_sort(int a[],int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{
		x=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>x)
			  a[j+1]=a[j];
			else
			  break;  
		}
		a[j+1]=x;
	}
	
}
