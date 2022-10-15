#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *head;
node *get_node(int x);
void creat_list();
void display();
void insert_beg();
void insert_mid();
void insert_end();
void insert_after_a_given_node();
void insert_before_a_given_node();
void del_beg();
void del_mid();
void del_end();
void del_before_an_element();
void del_after_an_element();
void del_an_element_from_a_perticular_position(); 
void reverse_link_list();
int main()
{
	char ch;
	int x;
	do
	{
		printf("----------------------------------------------\n");
		printf("|                   MANU                     |\n");
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
				creat_list();
				break;
			case 2:
				display();
				break;
			case 3:
				insert_beg();
				break;
			case 4:
				insert_mid();
				break;
			case 5:
				insert_end();
				break;
			case 6:
				insert_after_a_given_node();
				break;
			case 7:
				insert_before_a_given_node();
				break;
			case 8:
				del_beg();
				break;
			case 9:
				del_mid();
				break;
			case 10:
				del_end();
				break;
			case 11:
				del_before_an_element();
				break;
	               	case 12:
				del_after_an_element();
				break;
			case 13:
				del_an_element_from_a_perticular_position();
				break;
			case 14:
				reverse_link_list();
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
void creat_list()
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
        
}
void display()
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
void insert_beg()
{
	node *p;
	int x;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
	}
	printf("enter the value which you wand to insert at the begning ");
	scanf("%d",&x);
	p=get_node(x);
	p->next=head;
	head=p;
}
void insert_mid()
{
	node *p,*q;
	int x,pos,c=1;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
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
}
void insert_end()
{
	node *p,*q;
	int x;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
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
	
}
void insert_after_a_given_node()
{
	node *p,*q;
	int x,y;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
	}
	printf("enter the value after you want to insert ");
	scanf("%d",&y);
	printf("enter the value which you wand to insert after the node ");
	scanf("%d",&x);
	q=head;
	p=get_node(x);

	while(q->data!=y&&q->next!=NULL)
	{
		q=q->next;
	}
	if(q->data!=y)
	{
		printf("entered data %d not found\n",y);
		return;
	}   
	p->next=q->next;
	q->next=p;
}
void insert_before_a_given_node()
{
	node *p,*q,*r;
	int x,y;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
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
		return;
	}
	while(r->data!=y&&r->next!=NULL)
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
}
void del_beg()
{
	node *p;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
	}
	p=head;
	head=p->next;
	free(p);	
}
void del_mid()
{
	node *p,*q;
	int x;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
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
		return;
	} 
	if(p==q)
	head=head->next;
	else
	p->next=q->next;
	free(q);	
}
void del_end()
{
	node *p,*q;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
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
}
void del_before_an_element()
{
	node *p,*q,*r;
	int x;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
	}
	p=head;
	q=head;
	r=head;
	printf("enter the value whose previous value you wand to delete ");
	scanf("%d",&x);
	if(p->data==x||p->next==NULL)
	{
		printf("deletion can not be done bcz there are no element before your entered number\n");
		return;
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
		return;
	}
	if(q==head)
		head=r;
	p->next=q->next;
	free(q);
}
void del_after_an_element()
{
	node *p,*q;
	int x;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
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
		return;
	}
	if(p->data!=x)
	{
		printf("entered data not found\n");
		return;
	}
	q=p->next;
	p->next=q->next;
	free(q);
}
void del_an_element_from_a_perticular_position()
{
	node *p,*q;
	int pos,c=1;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
	}
	printf("enter the position which you want to delete ");
	scanf("%d",&pos);
	p=head;
	q=head;
	if(pos==1)
	{
		head=p->next;
		free(p);
		return;
	}
	while(c<=pos-1&&q->next!=NULL)
	{
		c++;
		p=q;
		q=q->next;
	}
	p->next=q->next;
    free(q);
}
void reverse_link_list()
{
	node *p,*q;
	if(head==NULL)
	{
		printf("link list not exist\n");
		return;
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
}
