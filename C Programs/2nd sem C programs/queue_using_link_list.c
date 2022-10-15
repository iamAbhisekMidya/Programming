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
		printf("|            QUEUE USING LINL LIST           |\n");
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
		printf("link list not exist\n");
		return;	
	}
	p=head;
	while(p!=NULL)
	{
		printf("[%d]->",p->data);
		p=p->next;
	}
	printf("\n\n");
}
node* insertion(node* head)
{
	node *get_node(int );
	node *p,*q;
	int x;
	printf("enter the value which you wand to insert ");
	scanf("%d",&x);
	p=get_node(x);
	if(p==NULL)
	{
		printf("queue is overflow\n");
	}
	else if(head==NULL)
	{
		head=p;
	}
	else
	{
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
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
	p=head;
	head=p->next;
	free(p);	
	return head;
}
