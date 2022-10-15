#include<stdio.h>
int main()
{
	void quick_sort_rc(int [],int ,int );
	int partition(int [],int ,int );
	int a[100],n,i,ch;
	printf("How many values you want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	quick_sort_rc(a,0,n-1);
	printf("\nThe array after quick sort:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 1;	
}
int partition(int a[],int left,int right)
{
	int pos,t;
	pos=left;
	while(left<=right)
	{
		while(a[pos]<=a[right]&&pos!=right)
	    	right--;
	    if(pos==right)
			return(pos);
		else
		{
			t=a[pos];
			a[pos]=a[right];
			a[right]=t;
			pos=right;
		}
		while(a[left]<=a[pos]&&left!=pos)
			left++;
		if(pos==left)
			return(pos);
		else
		{
			t=a[pos];
			a[pos]=a[left];
			a[left]=t;
			pos=left;
		}				
	}
}
void quick_sort_rc(int a[],int l,int r)
{
	int i;
	if(l<r)
	{
		i=partition(a,l,r);
		quick_sort_rc(a,l,i-1);
		quick_sort_rc(a,i+1,r);
	}
}
