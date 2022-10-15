#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	FILE *fp1,*fp2;
	char ch;
	int i;
	i=0;
	fp1=fopen(argv[1],"r");
	if(fp1==NULL)
	{
		printf("sourse file not open properly\n ");
		exit(0);
	}
	fp2=fopen(argv[2],"w");
	if(fp2==NULL)
	{
		printf("terget file not open properly\n ");
		exit(0);
	}
	printf("\nfile copied sucessfully\n\n\nthe contain of the terget file is\n\n\n");
	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp2);
		printf("%c",ch);
		i++;
	}
    printf("\n\n");
	fclose(fp1);
	fclose(fp2);
	return 1;
}
