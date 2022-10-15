#include<stdio.h>
#include<conio.h>
int main()
{
	int row,cal,space,i,j,k=0;
	printf("Enter the number of rows: ");
	scanf("%d",&row);
	row=row+2;
	if(row%2!=0)
		k=1;
	for(i=1;i<=row/2+k;i++)
    {
	   	for(space=1;space<=row-i;space++)
	  	{
		  if(i!=2)
	  		  printf("   ");
	    }
	   	for(j=1;j<=i;j++)
	  	{
	  		if(i==2)
	  			break;
	  		if(j==1||j==i)
	  			cal=1;
	  		else
	  			cal=0;
	  		printf("%d     ",cal);
  		}
  	   	if(i!=2)
	  		printf("\n");
	}
	for(i=row/2;i>=1;i--)
	{
	 	for(space=1;space<=row -i;space++)
	  	{
	    	if(i!=2)
	       		printf("   ");
	    }
	  	for(j=i;j>0;j--)
	  	{
	  		if(i==2)
	  			break;
	  		if(j==1||j==i)
	  			cal=1;
	  		else
	  			cal=0;
	  		printf("%d     ",cal);
  		}
		if(i!=2)
	  		printf("\n"); 
	}
	return 1;
}
