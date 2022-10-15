#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	int l=1,c=0,s=0,w=0;
	fp=fopen("a.txt","r");
	if(fp==NULL)
	{
		printf("file 1 not open\n");
		exit(0);
	}
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n'||ch==32)
		{
		     w++;
			if(ch=='\n')
			 l++;
		}
		else if(ch>32&&ch<48||ch>57&&ch<65||ch>90&&ch<97||ch>122&&ch<127)
			s++;
			
	c++;			
	}
	printf("line=%d\nword=%d\nspecial=%d\nchar=%d",l,w,s,c);
	return 1;
	
}
