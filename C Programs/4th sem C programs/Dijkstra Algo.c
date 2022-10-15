#include <stdio.h>
#define maxsize 20
int main()
{
	int n,s,t,d[maxsize][maxsize],i,j,label[maxsize],vect[maxsize],path[maxsize],m,z,p,w,x,c=1;
	printf("Enter the number of vertex : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	  	vect[i]=0;
	  	path[i]=0;
	  	label[i]=9999;
	  	for(j=1;j<=n;j++)
	  	   	d[i][j]=9999;
	}
	do{
	    printf("\nEnter vertex1 vertex2 and weight (0 0 0 for none) : ");
	  	scanf("%d%d%d",&i,&j,&w);
	  	if(i==0) 
			break;
	  	d[i][j]=w;
	} while(1);  
	printf("\nEnter the starting vertex Vs = ");
	scanf("%d",&s);
	printf("\nEnter the ending vertex Vt = ");
	scanf("%d",&t);
	printf("\n");
	vect[s]=1;
	label[s]=0;
	i=s;
	do{
		j=1;
		m=9999;
		while(j<=n)
		{
		  	if(vect[j]!=1)
		  	{
		  	  	z=d[i][j]+label[i];
		  	  	if(z<label[j])
		  	  	{
		  	  	   	label[j]=z;
		  	  		path[j]=i;
		  	  	}
		  	  	if(label[j]<m)
				{
					m=label[j];
					p=j;
				}   	
		  	}
			j=j+1;	
		}
		printf("\nIteration %d:-\n",c++);
		printf("\n Node\t    Lable\t Status\n\n");
    	for (x=1;x<=n;x++)
    	{
	  	  	if(label[x]==9999)
	  	  		continue;	
			printf(" %2d\t[ %4d, %2d ]\t",x,label[x],path[x]); 
	  	  	if(vect[x]==1)
	  	  		printf("Permanent\n");
	  	  	else
				printf("Temporary\n");	
		}
		vect[p]=1;
		i=p;
		printf("\nNow Node [ %2d ] become Parmanent.\n\n",p);
	}while(p!=t);
    printf("\n\nThe shortest distance between vertex %d to %d is = %d\n",s,t,label[t]);
	printf("\nThe shortest path from %d to %d is : ",s,t);
	i=t;
	printf("%d ",i);
	while(i!=s)
	{
	  	printf(" <- %d ",path[i]); 
	  	i=path[i];
	}
	printf("\n");
	return 1;	
}

