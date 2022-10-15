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
	node *merge_using_3rd_list(node *,node *);
	node *merge_without_using_3rd_list(node *,node *);
	node *head1=NULL,*head2=NULL,*head3=NULL;
	int x;
	do
	{
		printf("----------------------------------------------------\n");
		printf("|              MERGING OF LINK LIST                |\n");
		printf("----------------------------------------------------\n");
		printf("|1.creat list                                      |\n");
		printf("|2.display list                                    |\n");  
		printf("|3.marging 2 sorted link list using 3rd link list. |\n");
		printf("|4.marging 2 sorted link list without 3rd link lis.|\n");
		printf("|5.exit_from_the_program                           |\n");
		printf("----------------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				printf("[enter the first link list]\n\n");
				head1=creat_list(head1);
				printf("\n[enter the secound link list]\n\n");
				head2=creat_list(head2);
				head3=NULL;
				break;
			case 2:
				printf("first link list is:\n");
				display(head1);
				printf("secound link list is:\n");
				display(head2);
				if(head3!=NULL)
				{
					printf("the merged & sorted link list is:\n");
					display(head3);
				}
				break;
			case 3:
				head1=bubble_sort(head1);
				head2=bubble_sort(head2);
				head3=merge_using_3rd_list(head1,head2);
				break;
			case 4:
			    head1=bubble_sort(head1);
				head2=bubble_sort(head2);
				head3=merge_without_using_3rd_list(head1,head2);
				break;
			case 5:	
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
node *merge_using_3rd_list(node *head1,node *head2)
{
	node *head3,*p,*q,*r,*s;
	int x;
	head3=NULL;
	p=head1;
	q=head2;
	while(p!=NULL&&q!=NULL)
	{
		if(p->data<q->data)
		{
			x=p->data;
			p=p->next;
		}
		else
		{
			x=q->data;
			q=q->next;
		}
		r=get_node(x);
		if(head3==NULL)
		  head3=r;
		else
		  s->next=r;  
		s=r;
	}
	if(p==NULL)
	  p=q;
	while(p!=NULL)
	{
		r=get_node(p->data);
		if(head3==NULL)
		  head3=r;
		else
		  s->next=r;  
		s=r;
		p=p->next;	
	}
	return head3;  
}
node *merge_without_using_3rd_list(node *head1,node *head2)
{
	node *p,*q,*r,*s;
	int f1,f2;
	if(head1==NULL)
	  return head2;
	else if(head2==NULL)
	  return head1;
	p=head1;
	q=head2;  
	while(p!=NULL&&q!=NULL)   
	{
		f1=0;
		f2=0;
		while(p!=NULL&&q!=NULL&&p->data<q->data)
		{
			f1=1;
			s=p;
			p=p->next;
    	}
		if(f1==1)
		{
			s->next=q;
			s=p;
		}
		while(p!=NULL&&q!=NULL&&q->data<=p->data)
		{
			f2=1;
			r=q;
			q=q->next;
		}
		if(f2==1)
		{
			r->next=p;
			r=q;
		}
	} 
	if(head1->data<head2->data)
	  return head1;
	else
	  return head2;  
}
