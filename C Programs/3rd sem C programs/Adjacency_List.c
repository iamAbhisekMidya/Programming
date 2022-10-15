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
	int ch=1;
	while(ch==1)
	{
		fflush(stdin);
		printf("\nenter the node: ");
		scanf("%c",&x);
		p=get1(x);
		if(start==NULL)
			start=p;
		else
			q->next=p;
		q=p;	
		printf("\ndo you want to add more node ( yes=1 and no=0 ): ");
		scanf("%d",&ch);	
	}
	p=start;
	while(p!=NULL)
	{
		ch=1;
		while(ch==1)
		{
			printf("\nenter the adjacent vertex of %c : ",p->data);
			fflush(stdin);
			scanf("%c",&x);
			q=start;
			while(q!=NULL)
			{
				if(x==q->data)
					break;
				q=q->next;	
			}
			if(q==NULL)
				printf("\nplease enter right value\n");
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
			printf("\ndo you want to add more adjacent vertex of %c ( yes=1 and no=0 ): ",p->data);
			scanf("%d",&ch);
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
		printf("link list not exist.\n");
		return;
	}
	a=start;
	printf("\nThe requred result is:- \n");
	printf("\nNODE\tADJACENCY LIST\n\n");
	while(a!=NULL)
	{
		printf("%c\t",a->data);
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
