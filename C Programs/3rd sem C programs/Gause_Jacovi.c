#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,k,n,d,flag=0,iteration=0;
	float a[20][20],x[20],y[20],err,s;
	printf("Enter the number of equations: ");
	scanf("%d",&n);
	printf("\nEnter the correction upto decimal place: ");
  	scanf("%d",&d);
  	err=(5.0/pow(10,d));
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
	//Diagonaly dominant checking.
	for(i=0;i<n;i++)
	{
		s=0.0;
		for(j=0;j<n;j++)
		{
			if(i==j)
				continue;
			s=s+(fabs(a[i][j]));
		}
		if((fabs(a[i][i]))<s)
		{
			printf("\nThe entered system of linear equeation is not diagonaly dominant.\n");
			return 1;
		}
	}
	for(i=0;i<n;i++)
    {
	    x[i]=0.0;
	    y[i]=0.0;
    }
	do
	{
	    iteration++;
	    printf("\n\nIteration: %d\n\n",iteration);
	    for(i=0;i<n;i++)
	    {
	       x[i]=a[i][n];
	       for(j=0;j<n;j++)
		    {
		      	if(i==j)
					continue;
		        x[i]=x[i]-a[i][j]*y[j];
		    }
       		x[i]=x[i]/a[i][i];
	    }
		for(i=0;i<n;i++)
	    {
	      	flag=0;
	      	if((fabs(x[i]-y[i]))>err)
		    {
		        flag=1;
		        for(j=0;j<n;j++)
		        {
				    y[j]=x[j];
				}
		        break;
		    }
	    }
	    for(j=0;j<n;j++)
		{   
			printf("x[%d]=%f\t",j+1,x[j]);
		}
   	}while(flag==1);
	printf("\n\nThe solution is:\n");
	for(i=0;i<n;i++)
	{
	   printf("x[%d]=%f\n",i+1,x[i]);
	}
	return 1;
}
