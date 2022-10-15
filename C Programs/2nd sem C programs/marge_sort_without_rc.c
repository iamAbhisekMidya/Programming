#include<stdio.h>
#include<stdlib.h>
int main()
{
	void merge_sort_non_rc(int *,int );
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
	merge_sort_non_rc(a,n);
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
void merge_sort_non_rc(int a[],int n)
{
	int b[50],i,j,k,m,l1,l2,u1,u2,size;
	size=1;
	while(size<n)
	{
		k=0;
		l1=0;
		while(l1+size<n)
		{
			l2=l1+size;
			u1=l2-1;
			if(l2+size-1<n)
				u2=l2+size-1;
			else
				u2=n-1;
			i=l1;
			j=l2;
			while(i<=u1&&j<=u2)
			{
				if(a[i]<a[j])
				{
					b[k]=a[i];
					i++;
				}
				else
				{
					b[k]=a[j];
					j++;
				}
				k++;
			}
			while(i<=u1)
			{
				b[k]=a[i];
				k++;
				i++;
			}
			while(j<=u2)
			{
				b[k]=a[j];
				k++;
				j++;
			}
			l1=u2+1;	
		}
		for(m=0;m<k;m++)
		{
			a[m]=b[m];
		}
		size=size*2;
	}
}
