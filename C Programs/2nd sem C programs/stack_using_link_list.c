#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
int main()
{
	node *top=NULL;
	void display();
	node* push();
	node* pop();
	int x;
	do
	{
		printf("----------------------------------------------\n");
		printf("|          STACK USING LINK LIST             |\n");
		printf("----------------------------------------------\n");
		printf("|1.display list                              |\n");
		printf("|2.push                                      |\n");
		printf("|3.pop                                       |\n");
		printf("|4.exit_from_the_program                     |\n");
		printf("----------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				display(top);
				break;
			case 2:
				top=push(top);
				break;
			case 3:
				top=pop(top);
				break;
			case 4:	
				exit(0);
			default :
			    printf("wrong choice\n\n");	
            }
	}while(1);
    return 1;
}
void display(node* top)
{
	node *p;
	if(top==NULL)
	{
		printf("link list not exist\n");
		return;	
	}
	p=top;
	while(p!=NULL)
	{
		printf("[%d]->",p->data);
		p=p->next;
	}
	printf("\n\n");
}
node* push(node* top)
{
	node *p;
	int x;
	printf("enter the value which you wand to insert ");
	scanf("%d",&x);
	p=(node*)malloc(sizeof (node));
	if(p==NULL)
	{
		printf("stack is overflow\n");
		return top;
	}
	p->data=x;
	p->next=NULL;
	if(top==NULL)
		top=p;
	else
	{
		p->next=top;
		top=p;
    }
	return top;
}
node* pop(node* top)
{
	node *p;
	if(top==NULL)
	{
		printf("stack is underflow\n");
		return top;
	}
	p=top;
	top=p->next;
	printf("poped value is %d\n",p->data);
	free(p);	
	return top;
}	
