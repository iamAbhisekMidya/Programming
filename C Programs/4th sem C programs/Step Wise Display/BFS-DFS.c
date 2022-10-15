#include<stdio.h>
#include<stdlib.h>
#define maxlen 100
typedef struct node
{
	char data;
	int status;
	struct node *next;
    struct edge *adj;
}node;

typedef struct edge
{
	node *dest;
	struct edge *link;
}edge;

node *get1(char x)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->data=x;
	p->status=1;
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
	node *head=NULL;
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
		if(head==NULL)
			head=p;
		else
			q->next=p;
		q=p;	
		printf("\n");
	}
	p=head;
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
			q=head;
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
	printf("\n");
	return head;
}

void display(node *head)
{
	node *a;
	edge *b;
	if(head==NULL)
	{
		printf("Link list not exist.\n");
		return;
	}
	a=head;
	printf("The required result is:- \n");
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
	printf("\n");
}

void push(node *stack[],int *top,node **item)
{
	if(*top==maxlen-1)
	{
		printf("Stack is overflow.\n\n");
		return;
	}
	*top=*top+1;
	stack[*top]=*item;
}

void pop(node *stack[],int *top,node **item)
{
	if(*top==-1)
	{
		printf("Stack is underflow.\n\n");
		return;
	}
	*item=stack[*top];
	*top=*top-1;
}

void insertion(node *queue[],int *front,int *rear,node **item)
{
	if(*rear==maxlen-1)
	{
		printf("Queue is overflow.\n\n");
		return;
	}
	if(*front==-1)
	{
		*front=0;
		*rear=0;
	}
	else
		*rear=*rear+1;
	queue[*rear]=*item;	
}

void deletion(node *queue[],int *front,int *rear, node **item)
{
	if(*front==-1&&*rear==-1)
	{
		printf("Queue is underflow.\n\n");
		return;
	}
	else
	{
		if(*rear==*front)
		{
			*item=queue[*front];
			*front=-1;
			*rear=-1;
		}
		else
		{
			*item=queue[*front];
			*front=*front+1;
		}
	}
	
}

void bfs(node *head)
{
	node *p,*r,*a[maxlen],*y;
	edge *q;
	int front=-1,rear=-1,t=-1,i,j=-1;
	char x,ori[maxlen],b[maxlen],st,nd;
	if(head==NULL)
	{
		printf("Graph not exist.\n");
		return;
	}
	printf("Enter the starting vertex: ");
	fflush(stdin);
	scanf("%c",&x);
	st=x;
	printf("\nEnter the ending vertex: ");
	fflush(stdin);
	scanf("%c",&x);
	nd=x;
	x=st;
	p=head;
	printf("\n\n");
	while(p!=NULL)
	{
		if(p->data==x)
		{
			p->status=2;
			insertion(a,&front,&rear,&p);
			break;
		}
		else
			p=p->next;
	}
	if(p==NULL)
	{
		printf("\nPlease enter right starting vertex.\n\n");
		return;
	}
	printf("Front = %2d\tQueue = ",front+1);
	for(i=front;i<=rear&&rear>=0;i++)
	{
		y=a[i];		
		printf("%c ",y->data);
	}
	printf("\nRear  = %2d\tOrigin : ",rear+1);
	for(i=0;i<=t;i++)
		printf("%c ",ori[i]);
	printf("\n");
	while(1)
	{
		deletion(a,&front,&rear,&p);
		p->status=3;
		j++;
		b[j]=p->data;
		printf("\n%c removed from the Queue\n\n",p->data);
		if(p->data==nd)
			break;
		q=p->adj;
		while(q!=NULL)
		{
			if(q->dest->status==1)
			{
				q->dest->status=2;
				r=q->dest;
				insertion(a,&front,&rear,&r);
				t++;
				ori[t]=p->data;
			}
			q=q->link;
		}
		printf("Front = %2d\tQueue = ",front+1);
		for(i=front;i<=rear&&rear>=0;i++)
		{
			y=a[i];		
			printf("%c ",y->data);
		}
		printf("\nRear  = %2d\tOrigin : ",rear+1);
		for(i=0;i<=t;i++)
			printf("%c ",ori[i]);
		printf("\n");
		if(front==-1)
			break;
	}
	printf("\nThe BFS are: ");
	for(i=0;i<=j;i++)
		printf("%c ",b[i]);
	printf("\n\nThe shortest path between %c to %c is:  ",st,nd);
	printf("%c ",ori[0]);
	for(i=1;i<=t;i++)
	{
		if(ori[i]==ori[i-1])
			continue;
		printf("%c ",ori[i]);
	}
	printf("%c ",nd);		
	printf("\n\n");
	p=head;
	while(p!=NULL)
	{
		p->status=1;
		p=p->next;
	}
}
dispstack(node *a[maxlen],int top)
{
	int i=0;
	while(i<=top)
	{
		node *p=a[i];
		printf("%c ",p->data);
		i++;
	}
}
void dfs(node *head)
{
	node *p,*r,*a[maxlen];
	edge *q;
	int top=-1;
	int t=-1,i;
	char x,ds[100];
	if(head==NULL)
	{
		printf("Graph not exist.\n");
		return;
	}
	printf("Enter the starting vertex: ");
	fflush(stdin);
	scanf("%c",&x);
	p=head;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			p->status=2;
			push(a,&top,&p);
			break;
		}
		else
			p=p->next;
	}
	if(p==NULL)
	{
		printf("\nPlease enter right starting vertex.\n\n");
		return;
	}
	printf("\n\t STACK: ");
	dispstack(a,top);
	printf("\n");
	while(1)
	{
		pop(a,&top,&p);
		p->status=3;
		printf("Print %c  STACK: ",p->data);
		t++;
		ds[t]=p->data;
		q=p->adj;
		while(q!=NULL)
		{
			if(q->dest->status==1)
			{
				q->dest->status=2;
				r=q->dest;
				push(a,&top,&r);
			}
			q=q->link;
		}
		dispstack(a,top);
		printf("\n");
		if(top==-1)
			break;
	}
	printf("\nThe DFS are: ");
	for(i=0;i<=t;i++)
		printf("%c ",ds[i]);
	printf("\n\n");
	p=head;
	while(p!=NULL)
	{
		p->status=1;
		p=p->next;
	}
}

int main()
{
	node *head=NULL;
	int ch;
	do
	{
		printf("----------------------------------\n");
		printf("|           BFS AND DFS           |\n");
		printf("----------------------------------\n");
		printf("|1.CREATE GRAPH                   |\n");
		printf("|2.DISPLAY GRAPH                  |\n");
		printf("|3.BFS                            |\n");
		printf("|4.DFS                            |\n");
		printf("|5.EXIT                           |\n");
		printf("----------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
			    head=create();
				break;
			case 2:
				display(head);
				break;
			case 3:	
				bfs(head);
				break;
			case 4:
				dfs(head);
				break;
			case 5:	
				exit(0);
			default :
			    printf("Wrong choice...\n\n");	
        }
	}while(1);
    return 1;	
}
