#include<stdio.h>
#include<stdlib.h>
int main()
{
	void merge_sort(int *,int ,int );
	void merge(int *,int ,int ,int );
	void display(int *,int );
	int *a,n,i;
	printf("how many values you want to insert\n");
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		printf("array[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	printf("the given array before merge sort:\n");
	display(a,n);
	merge_sort(a,0,n-1);
	printf("the given array after merge sort:\n");
	display(a,n);
	return 1;	
}
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");  
}
void merge(int a[100],int low,int mid,int high)
{
	int b[100],i,j,h,k;
	i=low;               // [i] for maintain array [b](index)
	h=low;             //maintain laft side sorted sub array  [h to mid]
	k=mid+1;          //maintain right side sorted sub array  [k to high]
	while(h<=mid&&k<=high)
	{
		if(a[h]<=a[k])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[k];
			k++;
		}
		i++;
	}
	if(h>mid)     
	{
/*if left sorted array finished but right sort array remainning then copy the remeanning element of right sorted array into array [b].*/			
		for(j=k;j<=high;j++)
		{
			b[i]=a[j];
			i++;
		}
	}
	else
	{
/*if right sorted array finished but left sort array remainning then copy the remeanning element of left sorted array into array [b].*/			
		for(j=h;j<=mid;j++)
		{
			b[i]=a[j];
			i++;
		}
	}
/* copy the fully sorted array [b] into array [a]. */	
	for(j=low;j<=high;j++)
	{
		a[j]=b[j];
	}
}
void merge_sort(int a[100],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}	

}
