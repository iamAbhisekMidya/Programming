#include<stdio.h>
int main()
{
	void mod_bubble_sort(int *,int );
	int a[100],n,i,ch;
	printf("How many values you want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	mod_bubble_sort(a,n);
	printf("\nThe array after modified bubble sort:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 1;	
}
void mod_bubble_sort(int a[],int n)
{
	int i,j,t,flag=1;
	for(i=0;i<n-1&&flag==1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				flag=1;
			}
		}
	}
}
