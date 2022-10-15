#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	FILE *fp2;
	char ch[100];
	int i,n;
	FILE*fp1=fopen("e:/a.txt","r");
	if(fp1==NULL)
	{
		printf("a.txt file not open properly ");
		exit(0);
	}
	fp2=fopen("e:/b.txt","w");
	if(fp2==NULL)
	{
		printf("b.txt file not open properly ");
		exit(0);
	}
	printf("enter the maximum length of the string: ");
	scanf("%d",&n);
	while(fgets(ch,100,fp1)!=NULL)
 	{
		i=strlen(ch);
		if(i>=n)
		fputs(ch,fp2);
 	}
	printf("line stored sucessfully ");
	fclose(fp1);
	fclose(fp2);
	return 1;
}
