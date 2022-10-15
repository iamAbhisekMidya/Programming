#include<stdio.h>
#define maxsize 20
void disp_matrix(int [][maxsize],int );
void show_path(int [][maxsize],int ,int );
int main()
{
	int d[maxsize][maxsize],s[maxsize][maxsize],i,j,k,n;
	
	printf("Enter the number of vertex : ");   // Input Graph
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				d[i][j]=32767;
				s[i][j]=32767;
				continue;
			}
			printf("\nEnter weightage between [%d][%d] (if no edge then enter 32767) = ",i,j);
			scanf("%d",&d[i][j]);
			s[i][j]=j;
		}
		printf("\n");
	}
	
	printf("\n[ Step 0 ] :-\n");  // Display initial Step
	printf("\nDistance matrix D[0] :-\n\n");
	disp_matrix(d,n);
	printf("\n\nPath matrix S[0] :-\n\n");
	disp_matrix(s,n);
	
	for(k=1;k<=n;k++)   // Maintain Pivot Row And Column
	{
		for(i=1;i<=n;i++)    // Maintain row
		{
			if(i==k)    // Do not Need Operation On Pivot Row
				continue;
			for(j=1;j<=n;j++)  // Maintain Column
			{
				if(j==k||i==j)   // Do not Need Operation On Pivot Column And Digonal Element
					continue;	
				if(d[i][k]+d[k][j]<d[i][j])   // Calculation
				{
					d[i][j]=d[i][k]+d[k][j];
					s[i][j]=k;
				}	
			}
		}
		printf("\n\n[ Step %d ] :-\n",k);
		printf("\nDistance matrix D[%d] :-\n\n",k);
		disp_matrix(d,n);
		printf("\n\nPath matrix S[%d] :-\n\n",k);
		disp_matrix(s,n);
	}
	
	printf("\n\nEnter the two vertex whose distance you want to know :-\n");
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
	if(i==j)
	{
		printf("\nThe starting vertex and the ending vertex will not same.");
		return 1;
	}
	if(d[i][j]==32767)
	{
		printf("\nThere are no minimum distance between vertex %d to %d\n",i,j);
		printf("\nThere are no shortest path between vertex %d to %d",i,j);
		return 1;
	}
	printf("\nThe shortest distance between vertex %d to %d is = %d\n",i,j,d[i][j]);
	printf("\nThe shortest path from %d to %d is : ",i,j);
	printf("%d",i);
	show_path(s,i,j);	
	return 1;
}
void show_path(int s[][maxsize],int i,int j)
{
	if(s[i][j]==j)  // Exit Condition
	{
		printf(" -> %d",s[i][j]);
		return;
	}	
	show_path(s,i,s[i][j]);  // First To Middle
	show_path(s,s[i][j],j);  // Middle To Last
}
void disp_matrix(int a[][maxsize],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{	
		printf("| ");
		for(j=1;j<=n;j++)
 		{
		 	if(i==j)
		 		printf(" - ");
		 	else if(a[i][j]==32767)
				printf(" X ");
			else		
				printf("%2d ",a[i][j]);
   		}
   		printf("|\n");
	}
}
