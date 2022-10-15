#include<stdio.h>
int main()
{
	void quick_sort(int [],int );
	int partition(int [],int ,int );
	int a[100],n,i,ch;
	printf("How many values you want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	quick_sort(a,n);
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
void quick_sort(int a[],int n)
{
	int lower[50],upper[50],pos,beg,end,top=-1;
	if(n<=1)
		return;
	top=top+1;
	lower[top]=0;
	upper[top]=n-1;
	while(top!=-1)
	{
		beg=lower[top];
		end=upper[top];
		top=top-1;
		pos=partition(a,beg,end);
		if(beg+1<pos)
		{
			top=top+1;
			lower[top]=beg;
			upper[top]=pos-1;
		}
		if(end>pos+1)
		{
			top=top+1;
			lower[top]=pos+1;
			upper[top]=end;
		}
	}	
}
