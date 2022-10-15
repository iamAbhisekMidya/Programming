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
	int ch,item;
	node *head=NULL;
	node *get_node(int );
	node *creat_circular_ll(node *);
	void display(node *);
	node *ins_beg(node* );
	node *insert_mid(node *);
	node *ins_end(node* );
	node *insert_after_a_given_node(node *);
	node *insert_before_a_given_node(node *);
	node *del_beg(node* );
	node *del_mid(node *);
	node *del_end(node* );
	do
	{
		printf("----------------------------------------------\n");
		printf("|             CIRCULAR LINK LIST             |\n");
		printf("----------------------------------------------\n");
		printf("|1.creat list                                |\n");
		printf("|2.display list                              |\n");
		printf("|3.insert_beg                                |\n");
		printf("|4.insert_mid                                |\n");
		printf("|5.insert_end                                |\n");
		printf("|6.insert_after_a_given_node                 |\n");
		printf("|7.insert_before_a_given_node                |\n");
		printf("|8.del_beg                                   |\n");  
		printf("|9.del_mid                                   |\n");
		printf("|10.del_end                                  |\n");
		printf("|11.exit_from_the_program                    |\n");
		printf("----------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				head=creat_circular_ll(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				head=ins_beg(head);
				break;
			case 4:
				head=insert_mid(head);
				break;
			case 5:
				head=ins_end(head);
				break;
			case 6:
				head=insert_after_a_given_node(head);
				break;
			case 7:
				head=insert_before_a_given_node(head);
				break;
			case 8:
				head=del_beg(head);
				break;
			case 9:
				head=del_mid(head);
				break;
			case 10:
				head=del_end(head);
				break;
			case 11:	
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
	p=(node*)malloc(sizeof(node));
	p->data=x;
	p->next=NULL;
	return p;

}
node *creat_circular_ll(node *head)
{
	node *p;
	int x;
	char ch='y';
	head=NULL;
	while(1)
	{
		printf("if you do not want to add data then enter (-999)\nenter data ");
    	scanf("%d",&x);
        if(x==-999)
        break;
        else
        {
			p=get_node(x);
			if(head==NULL)
			{
				head=p;
				p->next=head;
			}
			else
			{
				p->next=head->next;
				head->next=p;
				head=p;	
			}
		}
	}
	return head;
}
void display(node *head)
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
node *ins_beg(node* head)
{
	node *p;
	int x;
	printf("enter the element ");
	scanf("%d",&x);
	p=get_node(x);
	if(head==NULL)
	{
		head=p;
		p->next=head;
	}
	else
	{
		p->next=head->next;
		head->next=p;
	}
	return head;
}
node *insert_mid(node *head)
{
	node *p,*q;
	int x,pos,c=1;
	printf("enter the value which you wand to insert at the middle ");
	scanf("%d",&x);
	printf("enter the position where you insert the given value ");
	scanf("%d",&pos);
	p=get_node(x);
	if(head==NULL)
	{
		head=p;
		p->next=p;
	}
	else if(pos==1)
	{
		p->next=head->next;
		head->next=p;	
	}
	else
	{
		q=head->next;
		while(c<pos-1&&q!=head)
		{
			c++;
			q=q->next;
		}
		if(q==head)
		{
			p->next=head->next;
			head->next=p;
			head=p;
		}
		else
		{
			p->next=q->next;
			q->next=p;
		}
		return head;
	}
}
node *ins_end(node* head)
{
	node *p;
	int x;
	printf("enter the element ");
	scanf("%d",&x);
	p=get_node(x);
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
node *insert_after_a_given_node(node *head)
{
	node *p,*q;
	int x,y;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	printf("enter the value which you wand to insert ");
	scanf("%d",&x);
	printf("enter the value after you want to insert ");
	scanf("%d",&y);
	q=head->next;
	p=get_node(x);

	while(q->data!=y&&q!=head)
	{
		q=q->next;
	}
	if(q->data!=y)
	{
		printf("entered data %d not found\n",y);
		return head;
	}   
	p->next=q->next;
	q->next=p;
	if(q==head)
	head=head->next;
	return head;
}
node *insert_before_a_given_node(node* head)
{
	node *p,*q,*r;
	int x,y;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	printf("enter the value which you wand to insert ");
	scanf("%d",&x);
	printf("enter the value of the node before you want to insert ");
	scanf("%d",&y);

	q=head->next;
	r=head->next;
	p=get_node(x);
	if(q->data==y)
	{
		p->next=head->next;
		head->next=p;
		return head;
	}
	while(r->data!=y&&r!=head)
	{
		q=r;
		r=r->next;
	}
	if(r->data!=y)
	{
		printf("entered data not found\n");
		return;
	} 
	p->next=q->next;
	q->next=p;
	return head;
}
node *del_beg(node* head)
{
	node *p;
	if(head==NULL)
	{
		printf("deletion from the begging can not be done bcz link list not exist\n");
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

node *del_end(node* head)
{
	node *p,*q;
	if(head==NULL)
	{
		printf("deletion from the end can not be done bcz link list not exist\n");
		return head;
	}
	p=head->next;
	while(p->next!=head)
		p=p->next;
	if(head==p)
		head=NULL;
	else
	{
	
		p->next=head->next;
		q=head;
		head=p;
		p=q;
	}
	free(p);
	return head;
}
node *del_mid(node *head)
{
	node *p,*q;
	int x;
	if(head==NULL)
	{
		printf("linl list not exist\n");
		return head;
	}
	printf("enter the element which you want to delete ");
	scanf("%d",&x);
	p=head->next;
	q=head->next;
	while(q!=head&&q->data!=x)
	{
		p=q;
		q=q->next;
	}
	if(q->data!=x)
	{
		printf("element not founf so deletion can not be done\n");
		return head;
	}
	if(p==q)
	{
		if(p==head)
			head=NULL;
		else
			head->next=p->next;	
	}
	else if(q==head)
	{
		head=p;
		head->next=q->next;
	}
	else
		p->next=q->next;
	free(q);
	return head;	
}
