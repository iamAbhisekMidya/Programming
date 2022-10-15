#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1;
	char ch;
	fp1=fopen("disp_own_sourse_code.c","r");
	if(fp1==NULL)
	{
		printf("file not open properly \n");
		exit(0);
	}
	while((ch=fgetc(fp1))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fp1);
	return 1;
}
