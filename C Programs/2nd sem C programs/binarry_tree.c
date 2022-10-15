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
	void preorder_using_rc(btree *);
	void preorder(btree *);
	void inorder_using_rc(btree *);
	void inorder(btree *);
	void postorder1(btree *);
	void postorder2(btree *);
	void postorder_using_rc(btree *);
	btree *root=NULL;
	char ch;
	int x;
	do
	{
		printf("--------------------------------------------------------------------\n");
		printf("|                         [BINARY TREE]                             |\n");
		printf("--------------------------------------------------------------------\n");
		printf("|1.tree [CREATION].                                                 |\n");
		printf("|2.tree [PREEORDER] traversing [without using recurssion].          |\n");
		printf("|3.tree [PREEORDER] traversing [using recurssion].                  |\n");
		printf("|4.tree [INORDER] traversing [without using recurssion].            |\n");
		printf("|5.tree [INORDER] traversing [using recurssion].                    |\n");
		printf("|6.tree [POSTORDER] traversing [without using recurssion][Method 1].|\n");
		printf("|7.tree [POSTORDER] traversing [without using recurssion][Method 2].|\n");
		printf("|8.tree [POSTORDER] traversing [using recurssion].                  |\n");
		printf("|9.[EXIT] from the program.                                         |\n");
		printf("--------------------------------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				root=create_tree();
				printf("\n");
				break;
			case 2:
				printf("preorder traversal is : ");
				preorder(root);
				printf("\n");
				break;
			case 3:
				printf("preorder traversal is : ");
				preorder_using_rc(root);
				printf("\n");
				break;
			case 4:
				printf("inorder traversal is : ");
				inorder(root);
				printf("\n");
				break;	
			case 5:
				printf("inorder traversal is : ");
				inorder_using_rc(root);
				printf("\n");
				break;
			case 6:
				printf("postorder traversal is : ");
				postorder1(root);
				printf("\n");
				break;
			case 7:
				printf("postorder traversal is : ");
				postorder2(root);
				printf("\n");
				break;			
			case 8:
				printf("postorder traversal is : ");
				postorder_using_rc(root);
				printf("\n");
				break;		
			case 9:	
				exit(0);
			default :
			    printf("wrong choice\n\n");	
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
	printf("enter the root element= ");
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
		printf("(press [ENTER] for none) enter the [LEFT] element of [%c]= ",p->data);
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
		printf("(press [ENTER] for none) enter the [RIGHT] element of [%c]= ",p->data);
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
void preorder(btree *root)
{
	btree *stack[50],*p;
	int top=-1;
	if(root==NULL)
	{
		printf("tree not exist");
		return;
	}
	p=root;
	while(1)
	{
		while(p!=NULL)
		{
			printf("%c ",p->data);
			if(p->right!=NULL)
			{
				top=top+1;
				stack[top]=p->right;
			}
			p=p->left;
		}
		if(top==-1)
			break;
		p=stack[top];
		top=top-1;	
	}
}
void inorder(btree *root)
{
	btree *stack[50],*p;
	int top=-1;
	if(root==NULL)
	{
		printf("tree not exist");
		return;
	}
	p=root;
	while(1)
	{
		while(p!=NULL)
		{
				top=top+1;
				stack[top]=p;
				p=p->left;
		}
		if(top==-1)
			break;	
		p=stack[top];
		top=top-1;	
		printf("%c ",p->data);
		p=p->right;
	}
}
void postorder1(btree *root)        //(method 1):(using 2 stack)  (logic->internet)
{
	btree *stack1[50],*stack2[50],*p;
	int top1=0,top2=-1;
		if(root==NULL)
	{
		printf("tree not exist");
		return;
	}
	stack1[top1]=root;
	while(top1!=-1)
	{
		p=stack1[top1];
		top1=top1-1;
		top2=top2+1;
		stack2[top2]=p;
		if(p->left!=NULL)
		{
			top1=top1+1;
			stack1[top1]=p->left;
		}
		if(p->right!=NULL)
		{
			top1=top1+1;
			stack1[top1]=p->right;
		}
	}
	while(top2!=-1)
	{
		p=stack2[top2];
		top2=top2-1;
		printf("%c ",p->data);
	}
}
void postorder2(btree *root)        //(method 2):(using 1 stack) (structure type stack)
{
	struct str
	{
		btree *add;
		int status;
	}stack[50];
	btree *p;
	int top=-1;
	if(root==NULL)
	{
		printf("tree not exist");
		return;
	}
	p=root;
	while(1)
	{
		while(p!=NULL)
		{
			top=top+1;
			stack[top].add=p;
			stack[top].status=0;
			p=p->left;
		}
		while(top!=-1&&stack[top].status==1)
		{
			printf("%c ",stack[top].add->data);
			top=top-1;
		}
		if(top==-1)
			break;
		stack[top].status=1;
		p=stack[top].add->right;	
	}
}
void preorder_using_rc(btree *root)
{
	if(root!=NULL)
	{
		printf("%c ",root->data);
		preorder_using_rc(root->left);
		preorder_using_rc(root->right);
	}
}
void inorder_using_rc(btree *root)
{
	if(root!=NULL)
	{
		inorder_using_rc(root->left);
		printf("%c ",root->data);
		inorder_using_rc(root->right);
	}
}
void postorder_using_rc(btree *root)
{
	if(root!=NULL)
	{
		postorder_using_rc(root->left);
		postorder_using_rc(root->right);
		printf("%c ",root->data);
	}
}

