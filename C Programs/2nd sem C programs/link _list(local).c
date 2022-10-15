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
	void display(node*);
	node* get_node(int );
	node* creat_list(node*);
	node* insert_beg(node*);
	node* insert_mid(node*);
	node* insert_end(node*);
	node* insert_after_a_given_node(node*);
	node* insert_before_a_given_node(node*);
	node* del_beg(node*);
	node* del_mid(node*);
	node* del_end(node*);
	node* del_before_an_element(node*);
	node* del_after_an_element(node*);
	node* del_an_element_from_a_perticular_position(node*); 
	node* reverse_link_list(node*);
	node* head=NULL;
	char ch;
	int x;
	do
	{
		printf("----------------------------------------------\n");
		printf("|               LINK LIST                    |\n");
		printf("----------------------------------------------\n");
		printf("|1.create list                                |\n");
		printf("|2.display list                              |\n");
		printf("|3.insert_beg                                |\n");
		printf("|4.insert_mid                                |\n");
		printf("|5.insert_end                                |\n");
		printf("|6.insert_after_a_given_node                 |\n");
		printf("|7.insert_before_a_given_node                |\n");
		printf("|8.del_beg                                   |\n");  
		printf("|9.del_mid                                   |\n");
		printf("|10.del_end                                  |\n");
		printf("|11.del_before_an_element                    |\n");
		printf("|12.del_after_an_element                     |\n");
		printf("|13.del_an_element_from_a_perticular_position|\n");
		printf("|14.reverse_link_list                        |\n");
		printf("|15.exit_from_the_program                    |\n");
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
				head=insert_beg(head);
				break;
			case 4:
				head=insert_mid(head);
				break;
			case 5:
				insert_end(head);
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
				head=del_before_an_element(head);
				break;
	        case 12:
				head=del_after_an_element(head);
				break;
			case 13:
				head=del_an_element_from_a_perticular_position(head);
				break;
			case 14:
				head=reverse_link_list(head);
				break;
			case 15:	
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
node* creat_list(node* head)
{
	node *p,*q;
	int x;
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
		  	 	head=p;
	        else
		    	q->next=p;
	        q=p;
		}
	}
    return head;    
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
		printf("[%d]->",p->data);
		p=p->next;
	}
	printf("\n\n");
}
node* insert_beg(node* head)
{
	node *p;
	int x;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	printf("enter the value which you wand to insert at the begning ");
	scanf("%d",&x);
	p=get_node(x);
	p->next=head;
	head=p;
	return head;
}
node* insert_mid(node* head)
{
	node *p,*q;
	int x,pos,c=1;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	printf("enter the value which you wand to insert at the middle ");
	scanf("%d",&x);
	printf("enter the position where you insert the given value ");
	scanf("%d",&pos);
	p=get_node(x);
	if(pos==1)
	{
		p->next=head;
		head=p;
		return;	
	}
	q=head;
	while(c<pos-1&&q->next!=NULL)
	{
		c++;
		q=q->next;
	}
	p->next=q->next;
	q->next=p;
	return head;
}
node* insert_end(node* head)
{
	node *p,*q;
	int x;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	printf("enter the value which you wand to insert at the end ");
	scanf("%d",&x);
	p=get_node(x);
	q=head;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	return head;
}
node* insert_after_a_given_node(node* head)
{
	node *p,*q;
	int x,y;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	printf("enter the value which you wand to insert after the node ");
	scanf("%d",&x);
	printf("enter the value after you want to insert ");
	scanf("%d",&y);
	q=head;
	p=get_node(x);
	while(q->data!=y&&q->next!=NULL)
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
	return head;
}
node* insert_before_a_given_node(node* head)
{
	node *p,*q,*r;
	int x,y;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	printf("enter the value before you want to insert ");
	scanf("%d",&y);
	printf("enter the value which you wand to insert before the node ");
	scanf("%d",&x);
	q=head;
	r=head;
	p=get_node(x);
	if(q->data==y)
	{
		p->next=head;
		head=p;
		return head;
	}
	while(r->data!=y&&r->next!=NULL)
	{
		q=r;
		r=r->next;
	}
	if(r->data!=y)
	{
		printf("entered data not found\n");
		return head;
	} 
	p->next=q->next;
	q->next=p;
	return head;
}
node* del_beg(node* head)
{
	node *p;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	p=head;
	head=p->next;
	free(p);
	return head;	
}
node* del_mid(node* head)
{
	node *p,*q;
	int x;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	p=head;
	q=head;
	printf("enter the value which you wand to delete ");
	scanf("%d",&x);
	while(q->data!=x&&q->next!=NULL)
	{
		p=q;
		q=q->next;
	}
	if(q->data!=x)
	{
		printf("entered data not found\n");
		return head;
	} 
	if(p==q)
	head=head->next;
	else
	p->next=q->next;
	free(q);	
	return head;
}
node* del_end(node* head)
{
	node *p,*q;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	p=head;
	q=head;
	while(q->next!=NULL)
	{
		p=q;
		q=q->next;
	}
	if(p==q)
	head=NULL;
	else
	p->next=NULL;
	free(q);
	return head;
}
node* del_before_an_element(node* head)
{
	node *p,*q,*r;
	int x;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	p=head;
	q=head;
	r=head;
	printf("enter the value whose previous value you wand to delete ");
	scanf("%d",&x);
	if(p->data==x||p->next==NULL)
	{
		printf("deletion can not be done bcz there are no element before your entered number\n");
		return head;
	}
	while(r->data!=x&&r->next!=NULL)
	{
		p=q;
		q=r;
		r=r->next;
	}
	if(r->data!=x)
	{
		printf("entered data not found\n");
		return head;
	}
	if(q==head)
		head=r;
	p->next=q->next;
	free(q);
	return head;
}
node* del_after_an_element(node* head)
{
	node *p,*q;
	int x;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	p=head;
	q=head;
	printf("enter the value whose next value you wand to delete ");
	scanf("%d",&x);
	while(p->data!=x&&p->next!=NULL)
	{
		p=p->next;
	}
	if(p->next==NULL)
	{
		printf("deletion can not be done bcz there are no element after your entered number\n");
		return head;
	}
	if(p->data!=x)
	{
		printf("entered data not found\n");
		return head;
	}
	q=p->next;
	p->next=q->next;
	free(q);
	return head;
}
node* del_an_element_from_a_perticular_position(node* head)
{
	node *p,*q;
	int pos,c=1;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	printf("enter the position which you want to delete ");
	scanf("%d",&pos);
	p=head;
	q=head;
	if(pos==1)
	{
		head=p->next;
		free(p);
		return head;
	}
	while(c<=pos-1&&q->next!=NULL)
	{
		c++;
		p=q;
		q=q->next;
	}
	p->next=q->next;
    free(q);
    return head;
}
node* reverse_link_list(node* head)
{
	node *p,*q;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return head;
	}
	p=NULL;
	q=head->next;
	while(head->next!=NULL)
	{
		head->next=p;
		p=head;
		head=q;
		q=q->next;
	}
	head->next=p;
	return head;
}
