#include<stdio.h>
#include<stdlib.h>
#define maxlen 100
void push(int stack[],int *top,int item)
{
	if(*top==maxlen-1)
	{
		printf("stack is overflow \n");
		return;
	}
	*top=*top+1;
	stack[*top]=item;
}
void pop(int stack[],int *top)
{
	if(*top==-1)
	{
		printf("stack is underflow\n");
		return;
	}
	printf("\npoped value is %d\n",stack[*top]);
	*top=*top-1;
}
void display(int stack[],int top)
{
	int i;
	if(top==-1)
	{
		printf("no element present in the stack\n");
		return;
	}
	for(i=top;i>=0;i--)	
	{
		printf("[%d] ",stack[i]);
	}
	printf("\n");
}
int main()
{
	int stack[maxlen],ch,top=-1,item;
	do
	{
		printf("----------------------------------------------\n");
		printf("|              STACK USING ARRAY             |\n");
		printf("----------------------------------------------\n");
		printf("|1.display list                              |\n");
		printf("|2.push                                      |\n");
		printf("|3.pop                                       |\n");
		printf("|4.exit_from_the_program                     |\n");
		printf("----------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				display(stack,top);
				break;
			case 2:
				printf("enter the element which you want to insert ");
				scanf("%d",&item);
				push(stack,&top,item);
				break;
			case 3:
				pop(stack,&top);
				break;
			case 4:	
				exit(0);
			default :
			    printf("wrong choice\n\n");	
        }
	}while(1);
    return 1;	
}

