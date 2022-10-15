#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char a[100];
	int b[100],i,l,sum,inb,oub;
	printf("enter the number ");
	gets(a);
	printf("enter the input bace and the output bace ");
	scanf("%d%d",&inb,&oub);
	sum=0;
	i=0;
	l=strlen(a);
	while(a[i]!='\0')
	{
		if(a[i]>='A'&&a[i]<='F')
			sum=sum+pow(inb,l-i-1)*(a[i]-55);
		else
			sum=sum+pow(inb,l-i-1)*(a[i]-48);
		i++;
	}
	i=0;
	while(sum!=0)
	{
		b[i]=sum%oub;
		sum=sum/oub;
		i++;
	}
	i=i-1;
	while(i>=0)
	{
		if(b[i]>=10&&b[i]<=15)
			printf("%c",b[i]+55);
		else
			printf("%d",b[i]);
		i--;
	}
	return 1;
}
