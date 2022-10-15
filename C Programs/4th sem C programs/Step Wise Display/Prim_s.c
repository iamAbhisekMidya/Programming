#include<stdio.h>
#define maxsize 20
int main()
{
	int d[maxsize][maxsize],r[maxsize][4],level[maxsize],i,j,k,n,p,q,c,sv,min,s;
	
	printf("Enter the number of vertex : ");   // Input the Graph
	scanf("%d",&n);
	for(i=1;i<=n;i++)   
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				d[i][j]=32767;
				continue;
			}
			printf("\nEnter weightage between [%d][%d] (if no edge then enter 32767) = ",i,j);
			scanf("%d",&d[i][j]);
		}
		printf("\n");
		level[i]=0;
	}
	
	printf("\nEnter the starting vertex: ");  // Input the starting vertex and set its level 1
	scanf("%d",&sv);
	level[sv]=1;
	
	c=0;   //maintain result array r[]
	
	for(k=1;k<=(n-1);k++)    // outer loop use to counting the edge which must be n-1 for n vertex
	{
		min=32767;
		for(i=1;i<=n;i++)
		{
			if(level[i]==1)
			{
				for(j=1;j<=n;j++)
				{
					if(level[j]!=1&&d[i][j]<min)  //Finding min distance of the new vertex whose level is 0
					{
						min=d[i][j];
						p=i;
						q=j;   // New vertex found
					}
				}
			}
		} 
		c++;          // Store result in the result array r[]
		r[c][1]=p;
		r[c][2]=q;
		r[c][3]=min;
		level[q]=1;     // Set the new vertex level 1
	}
	
	s=0;
	printf("\n\nThe minimum spanning tree is :\n\n"); 
	for(i=1;i<n;i++)
	{
		printf("[ %d, %d ] = %d\n\n",r[i][1],r[i][2],r[i][3]);	
		s=s+r[i][3];
	}
	printf("The cost of the minimum spanning tree is = %d unit\n",s);
	return 1;
}
