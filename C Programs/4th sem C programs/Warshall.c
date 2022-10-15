#include<stdio.h>
#define maxsize 20
void disp_matrix(int [][maxsize],int );
int main()
{
	int w[maxsize][maxsize],i,j,k,n;
	
	printf("Enter the number of vertex : ");  // Input the gtraph
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nIf there is a direct path between [%d][%d] [Y=1]/[N=0] = ",i,j);
			scanf("%d",&w[i][j]);
		}
		printf("\n");
	}
	
	printf("Step 0 :-\n\n");  // Display initial step
	disp_matrix(w,n);
	
	for(k=1;k<=n;k++)  // Maintain Pivot Column and Row
	{
		for(i=1;i<=n;i++)  // Maintain Row
		{
			if(w[i][k]==1)  // Finding the location in Pivot Column whose entry is 1 [Pi]
			{
				for(j=1;j<=n;j++)  // Maintain Column
				{
					if(w[k][j]==1)  // Finding the location in Pivot Row whose entry is 1 [Qj]
						w[i][j]=1;	// Put 1 in this position of W[Pi][Qj]
				}
			}
		}
		printf("\n\nStep %d :-\n\n",k);
		disp_matrix(w,n);
	}
	
	printf("\nEnter the starting vertex Vi = ");
	scanf("%d",&i);
	printf("\nEnter the ending vertex Vj = ");
	scanf("%d",&j);
	
	if(i<1||i>n)
	{
		printf("\nThe starting vertex is not found.");
		return 1;
	}
	else if(j<1||j>n)
	{
		printf("\nThe ending vertex is not found.");
		return 1;
	}
	
	if(w[i][j]==1) // Checking if there is a path between entered two vertices
		printf("\nThere exist a path between vertex %d and %d\n",i,j);
	else
		printf("\nThere does not exist a path between vertex %d and %d\n",i,j);
	return 1;
}
void disp_matrix(int a[][maxsize],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{	
		printf("|");
		for(j=1;j<=n;j++)	
			printf(" %d",a[i][j]);
   		printf(" |\n");
	}
}
