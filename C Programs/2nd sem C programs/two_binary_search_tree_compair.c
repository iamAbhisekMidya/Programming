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
	void compare_2_bst(bstree *,bstree *);
	void insert_bstree_wt_rc(bstree *, bstree *);
	void inorder_using_rc(bstree *);
	bstree *root1=NULL,*root2=NULL;
	int x,y,pos;
	do
	{
		printf("----------------------------------------------------------------------------------\n");
		printf("|                            [BINARY SEARCH TREE]                                 |\n");
		printf("----------------------------------------------------------------------------------\n");
		printf("|1.Binary search tree [COMPARE TWO BST ARE EQUAL OR NOT].                         |\n");
		printf("|2.Binary search tree [INORDER] traversing [using recurssion].                    |\n");
		printf("|3.[EXIT] from the program.                                                       |\n");
		printf("----------------------------------------------------------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			
			case 1:	
				printf("\nEnter the 1st BST:\n\n");
				root1=create_bstree_wt_rc();
				printf("\nEnter the 2nd BST:\n\n");
				root2=create_bstree_wt_rc();
				compare_2_bst(root1,root2);	
			    break;
			case 2:
				printf("\nInorder traversal of 1st BST is : ");
				inorder_using_rc(root1);
				printf("\nInorder traversal of 2nd BST is : ");
				inorder_using_rc(root2);
				printf("\n");
				break;	
			case 3:
				exit(0);
			default :
			    printf("Wrong choice\n\n");	
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
void compare_2_bst(bstree *root1,bstree *root2)
{
	bstree *p,*q,*stack1[50],*stack2[50];
	int top1=-1,top2=-1;
	if(root1==NULL||root2==NULL)
	{
		printf("\nthe two bst are not equeal\n\n");
		return;
	}
	p=root1;
	q=root2;
	while(1)
	{
		while(p!=NULL&&q!=NULL)
		{	
			if(p->data!=q->data)
			{
				printf("\nthe two bst are not equeal\n\n");
				return;
			}
		    if(p->left!=NULL&&q->left!=NULL)
			{
				if(p->left->data!=q->left->data)
				{
					printf("\nthe two bst are not equeal\n\n");
					return;
				}
			}
			if(p->right!=NULL&&q->right!=NULL)
			{
				if(p->right->data!=q->right->data)
				{
					printf("\nthe two bst are not equeal\n\n");
					return;
				}
			}
			if(p->right!=NULL)
			{
				top1++;
				stack1[top1]=p->right;
			}
			p=p->left;
			if(q->right!=NULL)
			{
				top2++;
				stack2[top2]=q->right;
			}
			q=q->left;
		}
		if(top1==-1||top2==-1)
			break;	
		p=stack1[top1];
		top1--;
		q=stack2[top2];
		top2--;			
	}
	if(top1==-1&&top2==-1)
		printf("\nthe two bst are equal\n\n");
	else
		printf("\nthe two bst are not equeal\n\n");
	
}
