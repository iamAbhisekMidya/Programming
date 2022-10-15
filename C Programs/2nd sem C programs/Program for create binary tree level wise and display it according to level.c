#include<stdio.h>
#include<stdlib.h>
typedef struct btree
{
	char data;
	struct btree *left,*right;
}btree;
int main()
{
	btree *get_node(char );
	btree *create_tree();
	void lable_traversing(btree *);
	btree *root=NULL;
	int x;
	do
	{
		printf("------------------------------------------------\n");
		printf("|                   [BINARY TREE]               |\n");
		printf("------------------------------------------------\n");
		printf("|1.Binary tree [CREATION].                      |\n");
		printf("|2.Binary tree [LABLE WISE] traversing.         |\n");
		printf("|3.[EXIT] from the program.                     |\n");
		printf("------------------------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				root=create_tree();
				printf("\n");
				break;
			case 2:
				printf("\nLable wise traversing is:\n\n");
				lable_traversing(root);
				break;
			case 3:	
				exit(0);
			default :
			    printf("Wrong choice\n\n");	
            }
	}while(1);
    return 1;
}
btree *get_node(char ch)
{
	btree *p;
	p=(btree*)malloc(sizeof (btree));
	p->data=ch;
	p->left=NULL;
	p->right=NULL;
	return p;
}
btree *create_tree()
{
	btree *queue[50],*root,*p;
	char ch;
	int front=0,rear=0;
	printf("Enter the root element: ");
	fflush(stdin);
	scanf("%c",&ch);
	root=get_node(ch);
	queue[rear]=root;
	while(front!=-1)
	{
		p=queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front=front+1;
		printf("(Press [ENTER] for none) enter the [LEFT] element of [%c]= ",p->data);
		fflush(stdin);
		scanf("%c",&ch);
		if(ch!='\n')
		{
			p->left=get_node(ch);
			if(front==-1)
			{
				front=0;
				rear=0;
			}
			else
				rear=rear+1;
			queue[rear]=p->left;
		}
		printf("(Press [ENTER] for none) enter the [RIGHT] element of [%c]= ",p->data);
		fflush(stdin);
		scanf("%c",&ch);
		if(ch!='\n')
		{
			p->right=get_node(ch);
			if(front==-1)
			{
				front=0;
				rear=0;
			}
			else
				rear=rear+1;
			queue[rear]=p->right;
    	}
	}
	return root;
}
void lable_traversing(btree *root)
{
	btree *queue[50],*p;
	int front=0,rear=0;
	if(root==NULL)
	{
		printf("\nTree not exist.....\n\n");
		return;
	}
	queue[rear]=root;
	while(front!=-1)
	{
		p=queue[front];
		printf("%c ",p->data);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front++;
		
		if(p->left!=NULL)
		{
			if(front==-1)
			{
				front=0;
				rear=0;
			}
			else
				rear++;
			queue[rear]=p->left;
		}
		if(p->right!=NULL)
		{
			if(front==-1)
			{
				front=0;
				rear=0;
			}
			else
				rear++;
			queue[rear]=p->right;
		}
	}
	printf("\n");
}
