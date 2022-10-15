#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

int main()
{
	node *get_node(int );
	void display(node*);
	node* insertion(node*);
	node* deletion(node* );
	node*head=NULL;
	int ch;
	do
	{
		printf("----------------------------------------------\n");
		printf("|        CIRCULAR QUEUE USING LINL LIST       |\n");
		printf("----------------------------------------------\n");
		printf("|1.display list                              |\n");
		printf("|2.insertion                                 |\n");
		printf("|3.deletion                                  |\n");
		printf("|4.exit_from_the_program                     |\n");
		printf("----------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
			    display(head);
				break;
			case 2:
				head=insertion(head);
				break;
			case 3:
				head=deletion(head);
				break;
			case 4:	
				exit(0);
			default :
			    printf("wrong choice\n\n");	
        }
	}while(1);
    return 1;	
}
node *get_node(int x)
{
	node *p;
	p=(node*)malloc(sizeof (node));
	p->data=x;
	p->next=NULL;
	return p;
}
void display(node*head)
{
	node *p;
	if(head==NULL)
	{
		printf("linl list not exist\n");
		return;
	}
	p=head->next;
	while(p!=head)
	{
		printf("[%d]->",p->data);
		p=p->next;
	}
	printf("[%d] \n",p->data);	
}
node* insertion(node* head)
{
	node *p;
	int x;
	printf("enter the element ");
	scanf("%d",&x);
	p=get_node(x);
	if(p==NULL)
	{
		printf("queue is overflow\n");
	}
	if(head==NULL)
	{
		head=p;
		p->next=p;
	}
	else
	{
		p->next=head->next;
		head->next=p;
		head=p;
	}
	return head;
}
node* deletion(node* head)
{
	node *p;
	if(head==NULL)
	{
		printf("queue is underflow\n");
		return head;
	}
    p=head->next;
	if(head==p)
		head=NULL;
	else
		head->next=p->next;
	free(p);
	return head;
}
