#include<stdio.h>
int main()
{
	int row,cal,space,i,j;
	printf("Enter the number of rows: ");
	scanf("%d",&row);
	for(i=0;i<row;i++)
	  {
	  	for(space=1;space<=row-i;space++)
	  	printf(" ");
	  	for(j=0;j<=i;j++)
	  	{
	  		printf("*");
  		}
	  	 printf("\n");
	}
	return 1;
}
