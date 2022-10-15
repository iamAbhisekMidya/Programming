#include<stdio.h>
struct dtl
{
	char name[20];
	int roll;
	int cla;
	int marks;
};
struct student
{
	int ben;
	int eng;
	int math;
	int coms;
	struct dtl t[10];
};
int main()
{
	int n,i,k;
	struct student m[10];
	printf("How many data you want to store: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the name: ");
		fflush(stdin);
		gets(m[i].t[i].name);
		printf("\nEnter the roll no: ");
		scanf("%d",&m[i].t[i].roll);
		printf("\nEnter the class: ");
		scanf("%d",&m[i].t[i].cla);
		printf("\nEnter the marks of bengali: ");
		scanf("%d",&m[i].ben);
		printf("\nEnter the marks of english: ");
		scanf("%d",&m[i].eng);
		printf("\nEnter the marks of math: ");
		scanf("%d",&m[i].math);
		printf("\nEnter the marks of computer: ");
		scanf("%d",&m[i].coms);
	    m[i].t[i].marks=m[i].ben + m[i].eng + m[i].math +m[i].coms;
	    printf("\n");
	}	
	for(i=0;i<n;i++)
	{
		printf("\n| The %d data is |\n\n\n",i+1);
		printf("The name is: %s\n\nThe roll number is: %d\n\nThe class is: %d\n\nThe total marks is: %d\n\nThe marks of bengali is: %d\n\nThe marks of english is: %d\n\nThe marks of math is: %d\n\nThe marks of computer is: %d\n\n",m[i].t[i].name,m[i].t[i].roll,m[i].t[i].cla,m[i].t[i].marks,m[i].ben,m[i].eng,m[i].math,m[i].coms);
	}
	printf("\n\nEnter the roll number of the perticular student whose data you want to scarch: ");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		if(k==m[i].t[i].roll)
		{	
			printf("The name is: %s\nThe roll number is: %d\nThe class is: %d\nThe total marks is: %d\nThe marks of bengali is: %d\nThe marks of english is: %d\nThe marks of math is: %d\nThe marks of computer is: %d\n",m[i].t[i].name,m[i].t[i].roll,m[i].t[i].cla,m[i].t[i].marks,m[i].ben,m[i].eng,m[i].math,m[i].coms);
			break;
		}	
	}
	return 1;
}
