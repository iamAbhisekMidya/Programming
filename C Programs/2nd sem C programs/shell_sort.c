#include<stdio.h>
#include<stdlib.h>
void shell_sort(int a[],int n)
{
	int gap,i,j,t;
	/* started with a larger gap, then reduce the gap to 1. We take gap sequence in order of n/2, n/4,n/8, ...1 */
	for(gap=n/2;gap>0;gap=gap/2)
	{
		/* we perform gapped inertion sort for this gap size. The fiest gap elements a[0...gap-1] are already in gapped order 
		keep adding one more element until the entire array is gap sorted */
		for(i=gap;i<n;i++)
		{
			//store a[i] in t and make a hole at position i
			t=a[i];
			//shift earlier gap sorted elements up until the correct location for a[i] is found
			for(j=i;j>=gap&&a[j-gap]>t;j=j-gap)
			{
				a[j]=a[j-gap];
			}
			//put t (the original a[i] in its correct location)
			a[j]=t;
		}
	}
}
int main()
{
	int a[50],n,i;
	printf("how many values you want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	shell_sort(a,n);
	printf("\nthe array after shell sort:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 1;
}
