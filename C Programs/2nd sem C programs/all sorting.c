#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int *create_array(int *,int *);
	void display(int *,int );
	void bubble_sort(int *,int );
	void mod_bubble_sort(int *,int );
	void selection_sort(int *,int );
	void insertion_sort(int *,int );
	void merge_sort_non_rc(int *,int );
	void merge_function_for_marge_sort_rc(int *,int ,int ,int );
	void merge_sort_rc(int *,int ,int );
	int partition(int *,int ,int );
	void quick_sort_rc(int *,int ,int );
	void quick_sort(int *,int );
	void del_max_heap(int *,int );
	void create_max_heap(int *,int ,int );
	void del_min_heap(int *,int );
	void create_min_heap(int *,int ,int );
	void radix_sort();
	void shell_sort(int *,int );
	void string_sort();
	int *a,n,i,x,item;
	do
	{
		printf("----------------------------------------------\n");
		printf("|                 [SORTING]                   |\n");
		printf("----------------------------------------------\n");
		printf("|1.Create Array.                              |\n");
		printf("|2.Display Array.                             |\n");
		printf("|3.Bubble Sort.                               |\n");
		printf("|4.Modified Bubble Sort.                      |\n");
		printf("|5.Selection Sort.                            |\n");
		printf("|6.Insertion Sort.                            |\n");
		printf("|7.Merge Sort.                                |\n");
		printf("|8.Merge Sort Using Recursion.                |\n");  
		printf("|9.Quick Sort.                                |\n");
		printf("|10.Quick Sort Using Recursion.               |\n");
		printf("|11.Max Heap Sort.                            |\n");
		printf("|12.Min Heap Sort.                            |\n");
		printf("|13.Radix Sort.                               |\n");
		printf("|14.Shell Sort.                               |\n");
		printf("|15.String Sort.                              |\n");
		printf("|16.Exit from the program.                    |\n");
		printf("----------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				a=create_array(a,&n);
				break;
			case 2:
				display(a,n);
				break;
			case 3:
				printf("the given array before bubble sort: \n");
				display(a,n);
				printf("\n");
				bubble_sort(a,n); 
				printf("\nthe given array after bubble sort:\n");
				display(a,n);
				printf("\n");
				break;
			case 4:
				printf("the given array before modified bubble sort: \n");
				display(a,n);
				printf("\n");
				mod_bubble_sort(a,n); 
				printf("\nthe given array after modified bubble sort:\n");
				display(a,n);
				printf("\n");
				break;
			case 5:
				printf("the given array before selection sort: \n");
				display(a,n);
				printf("\n");
				selection_sort(a,n);
				printf("\nthe given array after selection sort: \n");
				display(a,n);
				printf("\n");
				break;
			case 6:
				printf("the given array before insertion sort: \n");
				display(a,n);
				printf("\n");
				insertion_sort(a,n);
				printf("\nthe given array after insertion sort: \n");
				display(a,n);
				printf("\n");
				break;
			case 7:
				printf("the given array before merge sort: \n");
				display(a,n);
				printf("\n");
				merge_sort_non_rc(a,n);
				printf("\nthe given array after merge sort: \n");
				display(a,n);
				printf("\n");
				break;
			case 8:
				printf("the given array before merge sort: \n");
				display(a,n);
				printf("\n");
				merge_sort_rc(a,0,n-1);
				printf("\nthe given array after merge sort: \n");
				display(a,n);
				printf("\n");
				break;
			case 9:
				printf("the given array before quick sort: \n");
				display(a,n);
				printf("\n");
				quick_sort(a,n);
				printf("\nthe given array after quick sort: \n");
				display(a,n);
				printf("\n");
				break;
			case 10:
				printf("the given array before quick sort: \n");
				display(a,n);
				printf("\n");
				quick_sort_rc(a,0,n-1);
				printf("\nthe given array after quick sort: \n");
				display(a,n);
				printf("\n");
				break;
			case 11:
				printf("How many value you want to insert: ");
				scanf("%d",&n);
				a=(int *)malloc(sizeof(int)*(n+1));
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
				printf("\nthe given array after max heap sort: \n");
				display(a,n);	
				break;
	        case 12:
				printf("How many value you want to insert: ");
				scanf("%d",&n);
				a=(int *)malloc(sizeof(int)*(n+1));
				printf("\nEnter the root element: ");
				scanf("%d",&a[1]);
				for(i=2;i<=n;i++)
				{
					printf("Enter the element: ");
					scanf("%d",&item);
					create_min_heap(a,i,item);
				}
				printf("\nThe heap tree is:\n");
				display(a,n);
				for(i=n;i>1;i--)
					del_min_heap(a,i);
				printf("\nthe given array after min heap sort: \n");
				display(a,n);		
				break;
			case 13:
				radix_sort();
				break;
			case 14:
				printf("the given array before shell sort: \n");
				display(a,n);
				printf("\n");
				shell_sort(a,n);
				printf("\nthe given array after shell sort: \n");
				display(a,n);
				printf("\n");
				break;
			case 15:
				string_sort();
				break;
			case 16:	
				exit(0);
			default :
			    printf("wrong choice\n\n");	
        }
	}while(1);
    return 1;
}
int *create_array(int *a,int *n)
{
	int i;
	printf("how many values you want to insert: ");
	scanf("%d",&*n);
	a=(int *)malloc(sizeof(int)*(*n));
	for(i=0;i<*n;i++)
	{
		printf("array[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	return a;
}	
void display(int a[],int n)
{
	int i;
	printf("the given array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");  
}
void bubble_sort(int a[],int n)
{
	int i,j,t;
	display(a,n);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		display(a,n);
	}
}
void mod_bubble_sort(int a[],int n)
{
	int i,j,t,flag=1;
	display(a,n);
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
		display(a,n);
	}
}
void selection_sort(int a[],int n)
{
	int i,j,t,min;
	display(a,n);
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
		display(a,n);
	}
}
void insertion_sort(int a[],int n)
{
	int i,j,x;
	display(a,n);
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
		display(a,n);
	}
	
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
		display(a,n);
		size=size*2;
	}
}
void merge_function_for_marge_sort_rc(int a[100],int low,int mid,int high)
{
	int b[100],i,j,h,k;
	i=low;              
	h=low;            
	k=mid+1;          
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
		for(j=k;j<=high;j++)
		{
			b[i]=a[j];
			i++;
		}
	}
	else
	{
		for(j=h;j<=mid;j++)
		{
			b[i]=a[j];
			i++;
		}
	}	
	for(j=low;j<=high;j++)
	{
		a[j]=b[j];
	}
	display(a,high+1);
}
void merge_sort_rc(int a[100],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort_rc(a,low,mid);
		merge_sort_rc(a,mid+1,high);
		merge_function_for_marge_sort_rc(a,low,mid,high);
	}	
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
void create_min_heap(int a[],int n,int item)
{
	int ptr,par;
	ptr=n;
	while(ptr!=1)
	{
		par=ptr/2;
		if(a[par]>item)
			a[ptr]=a[par];
		else
			break;
		ptr=par;		
	}
	a[ptr]=item;
}
void del_min_heap(int a[],int n)
{
	int ptr,item;
	item=a[n];
	a[n]=a[1];
	n=n-1;
	ptr=1;
	while(2*ptr+1<=n)
	{
		if(item<a[2*ptr]&&item<a[2*ptr+1])
			break;
		else if(a[2*ptr]<a[2*ptr+1])	
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
	else if(item<a[2*ptr])
		a[ptr]=item;
	else
	{
		a[ptr]=a[2*ptr];
		a[2*ptr]=item;
	}
}
void radix_sort()
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
	printf("\nthe given array before radix sort: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
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
	printf("\nthe given array after radix sort: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
}
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
void string_sort()         
{
	char *a[50],t[50];;
	int i,n,j,min,c,s;
	printf("how many string you want to insert ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	  a[i]=(char *)malloc(sizeof(char)*50);
	  printf("enter the string[%d]= ",i+1);
	  fflush(stdin);
	  gets(a[i]);
	}
	printf("strings before sort: \n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			s=strcmp(a[i],a[j]);
			if(s>0)
			{
				strcpy(t,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],t);
			}
		}
	}
	printf("\nstring after sort:\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
	}
}
