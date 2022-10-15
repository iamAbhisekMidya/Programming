#include<stdio.h>
int main()
{
	void selection_sort(int *,int );
	int a[100],n,i,ch;
	printf("How many values you want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	selection_sort(a,n);
	printf("\nThe array after selection sort:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 1;	
}
void selection_sort(int a[],int n)
{
	int i,j,t,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			  min=j;
		}
		if(min!=i)
		{
			t=a[min];
			a[min]=a[i];
			a[i]=t;
		}
	}
}
