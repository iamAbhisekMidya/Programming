#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
int main()
{
	void display(node *);
	node *get_node(int );
	node *creat_list(node *);
	node *bubble_sort(node *);
	node *head=NULL;
	int x;
	do
	{
		printf("----------------------------------------------\n");
		printf("|                 LINK LIST                  |\n");
		printf("----------------------------------------------\n");
		printf("|1.creat list                                |\n");
		printf("|2.display list                              |\n");
		printf("|3.bubble sort                               |\n");
		printf("|4.exit_from_the_program                     |\n");
		printf("----------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				head=creat_list(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				head=bubble_sort(head);
				break;
			case 4:	
				exit(0);
			default :
			    printf("wrong choice\n\n");	
            }
	}while(1);
    return 1;	
}
node* get_node(int x)
{
	node*p;
	p=(node*)malloc(sizeof(node));
	p->data=x;
	p->next=NULL;
	return p;
}
void display(node* head)
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
		printf("[%d] ",p->data);
		p=p->next;
	}
	printf("\n\n");
}
node *creat_list(node* head)
{
	node *p,*q;
	head=NULL;
	int x,ch;
	printf("if you do not want to add data then enter (-999)\nenter data ");
    scanf("%d",&x);
    while(x!=-999)
    {
    	p=get_node(x);
    	if(head==NULL)
          head=p;
		else
		  q->next=p;
		q=p;
		printf("if you do not want to add data then enter (-999)\nenter data ");
        scanf("%d",&x);    	
   }
   return head;
}
node *bubble_sort(node *head)
{
	node *p,*q;
	int t;
	if(head==NULL)
	  return;
	p=head;
	while(p->next!=NULL)  
	{
		q=p->next;
		while(q!=NULL)
		{
			if(p->data>q->data)
			{
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
			q=q->next;
		}
		p=p->next;
	}
	return head;
}
