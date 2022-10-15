#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *next;
    struct edge *adj;
}node;

typedef struct edge
{
	node *dest;
	struct edge *link;
}edge;

node *start;

node *get1(char x)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->data=x;
	p->next=NULL;
	p->adj=NULL;
	return p;
}

edge *get2()
{
	edge *p;
	p=(edge *)malloc(sizeof(edge));
	p->dest=NULL;
	p->link=NULL;
	return p;
}

node *create()
{
	node *p,*q;
	edge *r,*s;
	char x,y;
	while(1)
	{
		fflush(stdin);
		printf("Enter the node (if no vertex then press only [enter]) : ");
		scanf("%c",&x);
		if(x=='\n')
			break;
		p=get1(x);
		if(start==NULL)
			start=p;
		else
			q->next=p;
		q=p;	
		printf("\n");
	}
	p=start;
	while(p!=NULL)
	{
		printf("\n");
		while(1)
		{
			printf("\nEnter the adjacent vertex of %c (if no vertex then press only [enter]) : ",p->data);
			fflush(stdin);
			scanf("%c",&x);
			if(x=='\n')
				break;
			q=start;
			while(q!=NULL)
			{
				if(x==q->data)
					break;
				q=q->next;	
			}
			if(q==NULL)
				printf("\nPlease enter right value.\n");
			else
			{
				r=get2();
				r->dest=q;
				if(p->adj==NULL)
					p->adj=r;
				else
					s->link=r;
				s=r;	
			}
		}
		p=p->next;	
	}
	return start;
}
void display(node *start)
{
	node *a;
	edge *b;
	if(start==NULL)
	{
		printf("\n\nlink list not exist.\n");
		return;
	}
	a=start;
	printf("\n\nThe required result is:- \n");
	printf("\n| NODE |  | ADJACENCY LIST \n\n");
	while(a!=NULL)
	{
		printf("|  %c   |  | ",a->data);
		b=a->adj;
		while(b!=NULL)
		{
			printf("%c ",b->dest->data);
			b=b->link;
		}
		a=a->next;
		printf("\n");
	}
}
int main()
{
	create();
	display(start);
	return 1;
}
