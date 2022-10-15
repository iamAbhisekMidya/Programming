#include<stdio.h>
#include<stdlib.h>
typedef struct bstree
{
	int data;
	struct bstree *left,*right;
}bstree;
int main()
{
	bstree *get_node(int );
	bstree *create_bstree_wt_rc();
	void level_traversing(bstree *);
	void insert_bstree_wt_rc(bstree *, bstree *);
	void inorder_using_rc(bstree *);
	bstree *root=NULL;
	int x,y,pos;
	do
	{
		printf("----------------------------------------------------------------------------------\n");
		printf("|                            [BINARY SEARCH TREE]                                 |\n");
		printf("----------------------------------------------------------------------------------\n");
		printf("|1.Binary search tree [CREATION].                                                 |\n");
		printf("|2.Binary search tree [LEVEL WISE] traversing.                                    |\n");
		printf("|3.Binary search tree [INORDER] traversing [using recurssion].                    |\n");
		printf("|4.[EXIT] from the program.                                                       |\n");
		printf("----------------------------------------------------------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			
			case 1:	
				printf("\nEnter the BST:\n\n");
				root=create_bstree_wt_rc();
			    break;
			case 2:
				printf("\nLevel wise traversing is:\n");
				level_traversing(root);
				break;
			case 3:
				printf("Inorder traversal is : ");
				inorder_using_rc(root);
				printf("\n");
				break;	
			case 4:
				exit(0);
			default :
			    printf("wrong choice\n\n");	
        }
	}while(1);
    return 1;
}
bstree *get_node(int x)
{
	bstree *p;
	p=(bstree*)malloc(sizeof (bstree));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
bstree *create_bstree_wt_rc()
{
	void insert_bstree_wt_rc(bstree *, bstree *);
	bstree *root,*new_node;
	int x;
	printf("Enter the root element: ");
	scanf("%d",&x);
	root=get_node(x);
	printf("(Enter[-999]for stop insertion process) Enter another data: ");
	scanf("%d",&x);
	while(x!=-999)
	{
	 	new_node=get_node(x);
	 	insert_bstree_wt_rc(root,new_node);
	 	printf("(Enter[-999]for stop insertion process) Enter another data: ");
	 	scanf("%d",&x);
	}
	return root;
}
void insert_bstree_wt_rc(bstree *root, bstree *new_node)
{
	bstree *p,*q;
	p=root;
	q=root;
	while(p!=NULL)
	{  
		q=p;
		if(new_node->data<p->data)
			p=p->left;
		else
			p=p->right;
	}
	if(new_node->data<q->data)
		q->left=new_node;
	else
		q->right=new_node;	
}
void inorder_using_rc(bstree *root)
{
	if(root!=NULL)
	{
		inorder_using_rc(root->left);
		printf("%d ",root->data);
		inorder_using_rc(root->right);
	}
}
void level_traversing(bstree *root)
{
	bstree *queue[50],*p;
	int front=0,rear=0;
	if(root==NULL)
	{
		printf("\ntree not exist.....\n\n");
		return;
	}
	queue[rear]=root;
	while(front!=-1)
	{
		p=queue[front];
		printf("%d ",p->data);
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
