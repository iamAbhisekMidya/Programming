#include<stdio.h>
int main()
{
	void display(int *,int );
	void del_max_heap(int *,int );
	void create_max_heap(int *,int ,int );
	int a[100],n,i,item;
	printf("How many value you want to insert: ");
	scanf("%d",&n);
	printf("\nEnter the root element: ");
	scanf("%d",&a[1]);
	for(i=2;i<=n;i++)
	{
		printf("Enter the element: ");
		scanf("%d",&item);
		create_max_heap(a,i,item);
	}
	printf("\nThe heap tree is:\n");
	display(a,n);
	for(i=n;i>1;i--)
		del_max_heap(a,i);
	printf("\nArray after heap sort:\n");
	display(a,n);	
	return 1;
}
void display(int a[],int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n\n");	
}
void create_max_heap(int a[],int n,int item)
{
	int ptr,par;
	ptr=n;
	while(ptr!=1)
	{
		par=ptr/2;
		if(a[par]<item)
			a[ptr]=a[par];
		else
			break;
		ptr=par;		
	}
	a[ptr]=item;
}
void del_max_heap(int a[],int n)
{
	int ptr,item;
	item=a[n];
	a[n]=a[1];
	n=n-1;
	ptr=1;
	while(2*ptr+1<=n)
	{
		if(item>a[2*ptr]&&item>a[2*ptr+1])
			break;
		else if(a[2*ptr]>a[2*ptr+1])	
		{
			a[ptr]=a[2*ptr];
			ptr=ptr*2;
		}
		else
		{
			a[ptr]=a[2*ptr+1];
			ptr=2*ptr+1;
		}
	}
	if(2*ptr>n)
		a[ptr]=item;
	else if(item>a[2*ptr])
		a[ptr]=item;
	else
	{
		a[ptr]=a[2*ptr];
		a[2*ptr]=item;
	}
}
