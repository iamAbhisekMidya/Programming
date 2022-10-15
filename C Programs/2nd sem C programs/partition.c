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
	void display(node*,node *);
	node* get_node(int );
	void creat_list(node**,node**);
	void even_odd_partition(node** ,node** );
	void positive_negative_partition(node**,node**);
	node* head1=NULL,* head2=NULL;
	char ch;
	int x;
	do
	{
		printf("----------------------------------------------\n");
		printf("|           PARTITION OF LINK LIST            |\n");
		printf("----------------------------------------------\n");
		printf("|1.Create list                                |\n");
		printf("|2.Display list                               |\n");
		printf("|3.Even odd partition                         |\n");
		printf("|4.Positive negative partition                |\n");
		printf("|5.Exit from the program                      |\n");
		printf("----------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				creat_list(&head1,&head2);
				break;
			case 2:
				display(head1,head2);
				break;
			case 3:
				even_odd_partition(&head1,&head2);
				break;
			case 4:
				positive_negative_partition(&head1,&head2);
				break;
			case 5:	
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
void creat_list(node** head1,node** head2)
{
	node *p,*q;
	int x;
	*head1=NULL;
	*head2=NULL;
    while(1)
    {
        printf("if you do not want to add data then enter (-999)\nenter data ");
    	scanf("%d",&x);
        if(x==-999)
        break;
        else
        {
		    p=get_node(x);
        	if(*head1==NULL)
		  	 	*head1=p;
	        else
		    	q->next=p;
	        q=p;
		}
	} 
}
void display(node* head1,node* head2)
{
	node *p;
	if(head1==NULL&&head2==NULL)
	{
		printf("link list not exist\n");
		return;	
	}
	p=head1;
	while(p!=NULL)
	{
		printf("[%d]->",p->data);
		p=p->next;
	}
	printf("\n");
	p=head2;
	while(p!=NULL)
	{
		printf("[%d]->",p->data);
		p=p->next;
	}
	printf("\n\n");
}
void even_odd_partition(node** head1,node** head2)
{
	node*p,*q,*r;
	if(*head1==NULL)
	{
		printf("link list not exist\n");
		return;
	}
	p=*head1;
	if(p->next==NULL)
		return;
	if(p->data%2==0)
	{
		while((p!=NULL)&&(p->data%2==0))
		{
			q=p;
			p=p->next;
		}
		r=p;
	}
	else
	{
		while((p!=NULL)&&(p->data%2!=0))
		{
			q=p;
			p=p->next;
		}
		r=q;
		q=p;
	}
	if(p==NULL)
		return;
	*head2=p;
	p=p->next;
	while(p!=NULL)
	{
		if(p->data%2==0)
		{
			q->next=p;
			q=p;
		}
		else
		{
			r->next=p;
			r=p;
		}
		p=p->next;
	}
	r->next=NULL;
	q->next=NULL;
}
void positive_negative_partition(node** head1,node** head2)
{
	node*p,*q,*r;
	if(*head1==NULL)
	{
		printf("link list not exist\n");
		return;
	}
	p=*head1;
	if(p->next==NULL)
		return;
	if(p->data>=0)
	{
		while((p!=NULL)&&(p->data>=0))
		{
			q=p;
			p=p->next;
		}
		r=p;
	}
	else
	{
		while((p!=NULL)&&(p->data<0))
		{
			q=p;
			p=p->next;
		}
		r=q;
		q=p;
	}
	if(p==NULL)
		return;
	*head2=p;
	p=p->next;
	while(p!=NULL)
	{
		if(p->data>=0)
		{
			q->next=p;
			q=p;
		}
		else
		{
			r->next=p;
			r=p;
		}
		p=p->next;
	}
	r->next=NULL;
	q->next=NULL;
}
