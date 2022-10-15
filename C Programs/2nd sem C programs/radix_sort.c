#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int a[10][20],b[20],top[10],n,i,j,k,l,len,pos;
	printf("Enter the highest length of the number: ");
	scanf("%d",&len);
	printf("\nHow many number you want to insert: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	//Radix sort technique
	for(i=0;i<len;i++)
	{
		//initialize the stack
		for(j=0;j<10;j++)
		{
			top[j]=(-1);
		}
		//separate digits from number and put into stack
		for(k=0;k<n;k++)
		{
			pos=(int)(b[k]/pow(10,i))%10;
			a[pos][++top[pos]]=b[k];
		}
		//collect elements from stacks to array b
		l=(-1);
		for(j=0;j<10;j++)
		{
			for(k=0;k<=top[j];k++)
			{
				b[++l]=a[j][k];
			}
		}
	}
	printf("\nSorted elements are....\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
	return 1;
}
