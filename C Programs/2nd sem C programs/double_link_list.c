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
	void create_double_link_list();
	void insert_beginning();
	void insert_middle();
	void insert_end();
	void delete_beginning();
	void delete_middle();
	void delete_end();
	void display();
	int x;
	do
	{
		printf("\n");
		printf("----------------------------------------------\n");
		printf("|            |DAUBLE LINK LIST|              |\n");
		printf("----------------------------------------------\n");
		printf("|1.Creat list                                |\n");
		printf("|2.Display list                              |\n");
		printf("|3.Insert beginning                          |\n");
		printf("|4.Insert middle                             |\n");
		printf("|5.Insert end                                |\n");
		printf("|6.Delete beginning                          |\n");  
		printf("|7.Delete middle                             |\n");
		printf("|8.Delete end                                |\n");
		printf("|9.Exit from the program                     |\n");
		printf("----------------------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				create_double_link_list();
				break;
			case 2:
				display();
				break;
			case 3:
				insert_beginning();
				break;
			case 4:
				insert_middle();
				break;
			case 5:
				insert_end();
				break;
			case 6:
				delete_beginning();
				break;
			case 7:
				delete_middle();
				break;
			case 8:
				delete_end();
				break;
			case 9:	
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
void create_double_link_list()
{
	dnode *p;
	int x;
	char ch='y';
	head1=NULL,head2=NULL;
	while(ch=='y'||ch=='Y')
	{
		printf("\nEnter the value: ");
		scanf("%d",&x);
		p=get_node(x);
		if(head1==NULL)
		{
			head1=p;
			head2=p;
		}
		else
		{
			head2->right=p;
			p->left=head2;
			head2=p;
		}
		printf("\nDo you continue (y/n): ");
		fflush(stdin);
		scanf("%c",&ch);
	}
}
void insert_beginning()
{
	dnode *p;
	int x;
	if(head1==NULL)
	{
		printf("\nLink list not exist.\n");
		return;
	}
	printf("\nEnter the value which you want to insert at beginning: ");
	scanf("%d",&x);
	p=get_node(x);
	p->right=head1;
	head1->left=p;
	head1=p;
	printf("\nValue added successfully.\n");
}
void insert_middle()
{
	dnode *p,*q;
	int x,pos,c=1;
	if(head1==NULL)
	{
		printf("\nLink list not exist.\n");
		return;
	}
	printf("\nEnter the value which you want to insert: ");
	scanf("%d",&x);
	printf("\nEnter the position where you want to insert the value %d : ",x);
	scanf("%d",&pos);
	p=get_node(x);
	if(pos==1)
	{
		p->right=head1;
		head1->left=p;
		head1=p;
		printf("\nValue added successfully.\n");
		return;
	}
	q=head1;
	while(c<pos-1&&q!=head2)
	{
		c++;
		q=q->right;
	}
	if(q==head2)
	{
		p->left=head2;
		head2->right=p;
		head2=p;
		printf("\nValue added successfully,\n");
		return;
	}
	p->right=q->right;
	p->left=q;
	q->right->left=p;   // or //   p->right->left=p;
	q->right=p;
	printf("\nValue added successfully.\n");
}
void insert_end()
{
	dnode *p;
	int x;
	if(head1==NULL)
	{
		printf("\nLink list not exist.\n");
		return;
	}
	printf("\nEnter the value which you want to insert at end: ");
	scanf("%d",&x);
	p=get_node(x);
	p->left=head2;
	head2->right=p;
	head2=p;
	printf("\nValue added successfully.\n");
}
void delete_beginning()
{
	dnode *p;
	if(head1==NULL)
	{
		printf("\nLink list not exist.\n");
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
void delete_middle()
{
	dnode *p;
	int x;
	if(head1==NULL)
	{
		printf("\nLink list not exist.\n");
		return;
	}
	printf("\nEnter the value which you want to delete: ");
	scanf("%d",&x);
	p=head1;
	while(p!=NULL&&p->data!=x)
	{
		p=p->right;
	}
	if(p==NULL)
	{
		printf("\n%d value not found\n",x);
		return;
	}
	if(p==head1)
	{
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
	}
	else if(p==head2)
	{
		head2=head2->left;
		head2->right=NULL;
	}
	else
	{
		p->right->left=p->left;
		p->left->right=p->right;
	}
	free(p);
	printf("\nValue deleted successfully.\n");
}
void delete_end()
{
	dnode *p;
	if(head1==NULL)
	{
		printf("\nLink list not exist.\n");
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
		printf("\nLink list not exist.\n");
		return;
	}
	printf("\nThe link list is:\n\n");
	p=head1;
	while(p!=NULL)
	{
		printf("[%d] ",p->data);
		p=p->right;
	}
	printf("\n");
}
