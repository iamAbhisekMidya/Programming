#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1,*fp2;
	char ch;
	fp1=fopen("E:/test1.txt","r");
	if(fp1==NULL)
	{
		printf("sourse file not open properly ");
		exit(0);
	}
	fp2=fopen("e:/test2.txt","w");
	if(fp2==NULL)
	{
		printf("tergect file not open properly ");
		exit(0);
	}
	while((ch=fgetc(fp1))!=EOF)
	{
		if(ch>=97)
		ch=ch-32;
		fputc(ch,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	printf("lower case to upper case convertion sucessfully ");
	return 1;
}

