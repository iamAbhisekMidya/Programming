#include<stdio.h>
#include<stdlib.h>
struct st
{
	char name[20];
	int cla;
	int marks;
};
int main()
{
	int n,i;
	struct st *m;
	printf("How many data you want to store: ");
	scanf("%d",&n);
	m=(struct st *)malloc(sizeof(struct st)*n);
	for(i=0;i<n;i++)
	{
		printf("\nenter name \n");
		fflush(stdin);
		gets(m[i].name);
		printf("\nenter the class\n");
		scanf("%d",&m[i].cla);
		printf("\nenter marks \n");
	    scanf("%d",&m[i].marks);
	}	
	for(i=0;i<n;i++)
	{
		printf("\nenter data %d is :->\n",i+1);
		printf("name is: %s\nclass is: %d\nmarks is: %d\n",m[i].name,m[i].cla,m[i].marks);
	}
	return 1;
}
