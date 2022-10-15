#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int coef, exp;
  struct node *next;
}node;

int main()
{
	
  node *get_node(int , int );	
  node *create_poly(node *);
  node *add_poly(node *, node *);
  node *sub_poly(node *, node *);
  void display_poly(node *);
  
  node *head1, *head2, *head3, *head4;
  
  head1=NULL;	
  head2=NULL;
  head3=NULL;
  head4=NULL;	
	
  printf("\nEnter the first polynomial expression:\n");
  
  head1=create_poly(head1);
  
  printf("\nThe first polynomial expression is: ");
  
  display_poly(head1);
  
  printf("\n\nEnter the secound polynomial expression:\n");
  
  head2=create_poly(head2);
  
  printf("\nThe secound polynomial expression is: ");
  
  display_poly(head2);
  
  printf("\n\n");
  
  head3=add_poly(head1, head2);
  
  printf("\n\nThe addition of two polynomial expression is: ");
  
  display_poly(head3);
  
  head4=sub_poly(head1, head2);
  
  printf("\n\nThe subtraction of two polynomial expression is: ");

  display_poly(head4);
  
  printf("\n\n");
  
  return 1;
}

node *get_node(int x, int y)
{

  node*p;
  
  p=(node*)malloc(sizeof(node));
  
  p->coef=x;
  p->exp=y;
  p->next=NULL;
  
  return p;
}

node *create_poly(node *head)
{

  node *p, *q;
  int x, y;
  char ch='y';
  head=NULL;
  
  while(ch=='y'||ch=='Y')
  {
    printf("\nEnter the coefficient: ");
    scanf("%d", &x);
    printf("\nEnter the exponent: ");
    scanf("%d", &y);

    p=get_node(x, y);
    
    if(head==NULL)
      head=p;

    else
      q->next=p;
    
    q=p;

    printf("\nContinue adding more terms ?(y/n): ");
	fflush(stdin);	
    scanf("%c",&ch);
  }
  
  return head;
}

void display_poly(node *head)
{

  node*p;

  if(head==NULL)
    printf("\nLink list not exist\n\n");

  p=head;
  printf("%dX^%d",p->coef,p->exp); 
  p=p->next;
  while(p!=NULL)
  {
    if(p->coef<0)
      printf("%dX^%d",p->coef,p->exp);
    else
      printf("+%dX^%d",p->coef,p->exp);
    p=p->next;
  }
}

node *add_poly(node *head1, node *head2)
{
  int x, y;
  node *head3, *p, *q, *r, *s;
  
  head3=NULL;
  
  if(head1==NULL||head2==NULL)
    return head3;

  p=head1;
  q=head2;
  while(p!=NULL&&q!=NULL)
  {
    if(p->exp>q->exp)
    {
      x=p->coef;
      y=p->exp;
      p=p->next;
    }

    else if(q->exp>p->exp)
    {
      x=q->coef;
      y=q->exp;
      q=q->next;
    }
    
    else
    {
      x=((p->coef)+(q->coef));
      y=p->exp;
      p=p->next;
      q=q->next;
    }
    
    r=get_node(x, y);

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

    r=get_node(p->coef, p->exp);
 
    if(head3==NULL)
      head3=r;

    else
      s->next=r;

    s=r;  
    p=p->next;
    
  }
  
  return head3;
}

node *sub_poly(node *head1, node *head2)
{

  int x, y;
  node *head3, *p, *q, *r, *s;
  
  head3=NULL;
  
  if(head1==NULL||head2==NULL)
    return head3;

  p=head1;
  q=head2;
  while(p!=NULL&&q!=NULL)
  {
    if(p->exp>q->exp)
    {
      x=p->coef;
      y=p->exp;
      p=p->next;
    }

    else if(q->exp>p->exp)
    {
      x=(q->coef *(-1));
      y=q->exp;
      q=q->next;
    }
    
    else
    {
      x=((p->coef)-(q->coef));
      y=p->exp;
      p=p->next;
      q=q->next;
    }
    
    r=get_node(x, y);

    if(head3==NULL)
      head3=r;
   
    else
      s->next=r;

    s=r;  
  }
 
  while(p!=NULL)
  {

    r=get_node(p->coef, p->exp);
 
    if(head3==NULL)
      head3=r;

    else
      s->next=r;

    s=r;  
    p=p->next;
    
  }
  
  while(q!=NULL)
  {

    r=get_node((q->coef *(-1)), q->exp);
 
    if(head3==NULL)
      head3=r;

    else
      s->next=r;

    s=r;  
    q=q->next;
    
  }

  return head3;
}

