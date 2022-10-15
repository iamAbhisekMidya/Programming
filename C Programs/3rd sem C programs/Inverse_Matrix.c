#include <stdio.h>
int main()
{
	float a[10][10],b[10][10],r;
	int i,j,k,n;
	printf("Enter the order of the square matrix: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\na[%d][%d]=",i+1,j+1);
			scanf("%f",&a[i][j]);
			//For identity matrix
			if(i==j)
				b[i][j]=1.0;
			else
				b[i][j]=0.0;
		}
		printf("\n");
	}
	printf("\n\nThe main matrix is:-\n\n");
	for(i=0;i<n;i++)
	{
		printf("| ");
		for(j=0;j<n;j++)
		{
			printf("%5.2f ",a[i][j]);
		}
		printf("|\n");
	}
	//inverse of the matrix
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(k==i)
				continue;
			r=a[i][k]/a[k][k];
			for(j=0;j<n;j++)
			{
				a[i][j]=a[i][j]-r*a[k][j];
				b[i][j]=b[i][j]-r*b[k][j];
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
       		printf(" |\t");
       		printf("|");
    		for(j=0;j<n;j++)
	 		{
			 	printf("%5.2f",b[i][j]);
       		}
       		printf(" |\n");
		}
		printf("\n");
		//Steps display stop.	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=b[i][j]/a[i][i];
		}
		a[i][i]=a[i][i]/a[i][i];
	}
	//last step display
	printf("\nStep %d:-\n\n",k+1);
	for(i=0;i<n;i++)
	{	
		printf("|");
		for(j=0;j<n;j++)
 		{
		 	printf("%5.2f",a[i][j]);
   		}
   		printf(" |\t");
   		printf("|");
		for(j=0;j<n;j++)
 		{
		 	printf("%5.2f",b[i][j]);
   		}
   		printf(" |\n");
	}
	printf("\n");
	printf("\n\nThe inverse matrix is:-\n\n");
	for(i=0;i<n;i++)
	{
		printf("| ");
		for(j=0;j<n;j++)
		{
			printf("%5.2f ",b[i][j]);
		}
		printf("|\n");
	}
	return 0;
}
