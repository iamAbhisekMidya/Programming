#include<stdio.h>
#include<stdlib.h>
typedef struct dnode
{
	int data;
	struct dnode *left,*right;
}dnode;
dnode *head1=NULL,*head2=NULL;
int main()
{
	dnode *get_node(int );
	void insert_beginning();
	void insert_end();
	void delete_beginning();
	void delete_end();
	void display();
	int x;
	do
	{
		printf("\n\n");
		printf("----------------------------------------------\n");
		printf("|            |DAUBLE ENDED QUEUE|            |\n");
		printf("----------------------------------------------\n");
		printf("|1.Insert element into queue                 |\n");  
		printf("|2.Delete element from queue                 |\n");
		printf("|3.Display queue                             |\n");
		printf("|4.Exit from the program                     |\n");
		printf("----------------------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				printf("----------------------------------------------\n");
				printf("|                  |INSERT|                   |\n");
				printf("----------------------------------------------\n");
				printf("|1.Insert at beginning                        |\n");  
				printf("|2.Insert at end                              |\n");
				printf("----------------------------------------------\n");
				printf("Enter your choice: ");
				scanf("%d",&x);
				if(x==1)
					insert_beginning();
				else if(x==2)
					insert_end();
				else
					printf("Wrong choice..\n\n");
				break;
			case 2:
				printf("----------------------------------------------\n");
				printf("|                  |DELETE|                   |\n");
				printf("----------------------------------------------\n");
				printf("|1.Delete at beginning                        |\n");  
				printf("|2.Delete at end                              |\n");
				printf("----------------------------------------------\n");
				printf("Enter your choice: ");
				scanf("%d",&x);
				if(x==1)
					delete_beginning();
				else if(x==2)
					delete_end();
				else
					printf("Wrong choice..\n\n");
				break;
			case 3:
				display();	
				break;
			case 4:	
				exit(0);
			default :
			    printf("Wrong choice\n\n");	
        }
	}while(1);
    return 1;
}
dnode *get_node(int x)
{
	dnode *p;
	p=(dnode *)malloc(sizeof(dnode));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void insert_beginning()
{
	dnode *p;
	int x;
	printf("\nEnter the value which you want to insert at beginning: ");
	scanf("%d",&x);
	p=get_node(x);
	if(p==NULL)
	{
		printf("\nDqueue is overflow.\n");
		return;
	}
	if(head1==NULL)
	{
		head1=p;
		head2=p;	
	}
	else
	{
		p->right=head1;
		head1->left=p;
		head1=p;
	}
	printf("\nValue added successfully.\n");
}
void insert_end()
{
	dnode *p;
	int x;
	printf("\nEnter the value which you want to insert at end: ");
	scanf("%d",&x);
	p=get_node(x);
	if(p==NULL)
	{
		printf("\nDqueue is overflow.\n");
		return;
	}
	if(head1==NULL)
	{
		head1=p;
		head2=p;	
	}
	else
	{	
		p->left=head2;
		head2->right=p;
		head2=p;
	}
	printf("\nValue added successfully.\n");
}
void delete_beginning()
{
	dnode *p;
	if(head1==NULL)
	{
		printf("\nDqueue is undeflow.\n");
		return;
	}
	p=head1;
	if(head1==head2)
	{
		head1=NULL;
		head2=NULL;
	}
	else
	{
		head1=head1->right;
		head1->left=NULL;
	}
	free(p);
	printf("\nValue deleted successfully.\n");
}
void delete_end()
{
	dnode *p;
	if(head1==NULL)
	{
		printf("\nDqueue is underflow.\n");
		return;
	}
	p=head2;
	if(head1==head2)
	{
		head1=NULL;
		head2=NULL;
	}
	else
	{
		head2=head2->left;
		head2->right=NULL;
	}
	free(p);
	printf("\nValue deleted successfully.\n");
}
void display()
{
	dnode *p;
	if(head1==NULL)
	{
		printf("\nDqueue not exist.\n");
		return;
	}
	printf("\nThe dqueue is:\n\n");
	p=head1;
	while(p!=NULL)
	{
		printf("[%d] ",p->data);
		p=p->right;
	}
	printf("\n");
}
