#include<stdio.h>
int main()
{
	int i,j,k,n;
	float a[20][20],x[20],r;
	printf("Enter the number of equations: ");
	scanf("%d",&n);
	//Input the matrix.
	printf("\nEnter co-efficient matrix [A] row wise:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\na[%d][%d]= ",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
		printf("\n");
	}
	printf("\n\nEnter column matrix [B] row wise:\n");
	for(i=0,j=n;i<n;i++)
	{
		printf("\nb[%d]= ",i+1);
		scanf("%f",&a[i][j]);
	}
	printf("\n");
	//Upper triangular matrix conversion
	for(k=0;k<n-1;k++)
	{
		for(i=k+1;i<n;i++)
		{
			r=a[i][k]/a[k][k];
			for(j=0;j<=n;j++)
			{
				a[i][j]=a[i][j]-r*a[k][j];
			}
		}
		//Steps display start. [optional]
		printf("\nStep %d:-\n\n",k+1);
		for(i=0;i<n;i++)
    	{	
    		printf("|");
    		for(j=0;j<n;j++)
	 		{
			 	printf("%5.2f",a[i][j]);
       		}
       		printf(" |\t| %5.2f |\n",a[i][j]);
		}
		printf("\n");
		//Steps display stop.
	}
	//Back tracking
	x[n-1]=a[n-1][n]/a[n-1][n-1];
	for(j=n-2;j>=0;j--)
	{
	    x[j]=a[j][n];
	    for(i=n-1;i>j;i--)
	    {
	    	x[j]=x[j]-a[j][i]*x[i];
	    }
	    x[j]=x[j]/a[j][j];
	}
	printf("\nThe solution is:\n");
	for(i=0;i<n;i++)
	{
	   printf("x[%d]=%5.2f\n",i+1,x[i]);
	}
	return 1;
}
