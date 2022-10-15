#include<stdio.h>
int cti(char p[])
{
	int i=0,sum=0;
	if(p[i]=='-')
		i++;
	while(p[i]!='\0')
	{
		sum=sum*10+p[i]-48;
		i++;	
	}
	if(p[0]=='-')
		return (sum*(-1));
	else
		return sum;	
}
int main(int argc,char *argv[])
{
	int i=0;
	printf("The numbers is/are : ");
	for(i=1;i<argc;i++)
		printf("%d ",cti(argv[i]));
	return 1;	
}
