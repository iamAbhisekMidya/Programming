#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k;
	char str[10];
	printf("enter the binary number ");
	gets(str);
	k=strlen(str);
	k=k-1;
	j=k;
	while(str[k]!='1')
	{
		k=k-1;
		if(k==-1)
		 break;
	}
	k=k-1;
	while(k>=0)
	{
		if(str[k]=='0')
           str[k]='1';
        else   
		  str[k]='0';
		k=k-1;    
	}
	for(i=0;i<=j;i++)
	{
		printf("%d ",str[i]-48);
	}
	return 1;
	
}
