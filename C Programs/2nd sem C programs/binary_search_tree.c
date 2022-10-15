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
	bstree *create_bstree_using_rc(bstree *);
	bstree *del_node(bstree *, int );
	void insert_bstree_wt_rc(bstree *, bstree *);
	void insert_bstree_using_rc(bstree *, bstree *);
	int bin_search_wt_rc(bstree *, int );
	int bin_search_using_rc(bstree *, int );
	void preorder_using_rc(bstree *);
	void inorder_using_rc(bstree *);
	void postorder_using_rc(bstree *);
	bstree *root=NULL;
	int x,y,pos;
	do
	{
		printf("----------------------------------------------------------------------------------\n");
		printf("|                            [BINARY SEARCH TREE]                                 |\n");
		printf("----------------------------------------------------------------------------------\n");
		printf("|1.Binary search tree [CREATION][without using recurssion].                       |\n");
		printf("|2.Binary search tree [CREATION][using recurssion].                               |\n");
		printf("|3.Binary search tree [DELETION] a node.                                          |\n");
		printf("|4.Binary search tree [SCARCHING][BINARY SCARCH][without using recurssion].       |\n");
		printf("|5.Binary search tree [SCARCHING][BINARY SCARCH][using recurssion].               |\n");
		printf("|6.Binary search tree [PREEORDER] traversing [using recurssion].                  |\n");
		printf("|7.Binary search tree [INORDER] traversing [using recurssion].                    |\n");
		printf("|8.Binary search tree [POSTORDER] traversing [using recurssion].                  |\n");
		printf("|9.[EXIT] from the program.                                                       |\n");
		printf("----------------------------------------------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				printf("Please enter [INTEGER] values:\n\n");
				root=create_bstree_wt_rc();
				printf("\n");
				break;
	  		case 2:
			    printf("Please enter [INTEGER] values:\n\n");
				printf("Enter the root element: ");
				scanf("%d",&x);
				root=get_node(x);
				root=create_bstree_using_rc(root);
				printf("\n");
				break;
			case 3:	
				printf("Enter the value which you want to delete: ");
				scanf("%d",&y);
				root=del_node(root,y);	
			    break;
			case 4:
				printf("\nEnter element to search: ");
				scanf("%d",&y);
				pos=bin_search_wt_rc(root,y);
				if(pos==-1)
				   printf("item %d not found\n",y);
				else
				   printf("item %d is found\n",y);    	
				break;
			case 5:
				printf("\nEnter element to search: ");
				scanf("%d",&y);
				pos=bin_search_using_rc(root,y);
				if(pos==-1)
				   printf("item %d not found\n",y);
				else
				   printf("item %d is found\n",y);    	
				break;	
			case 6:
				printf("\nPreorder traversal is : ");
				preorder_using_rc(root);
				printf("\n");
				break;
			case 7:
				printf("\nInorder traversal is : ");
				inorder_using_rc(root);
				printf("\n");
				break;
			case 8:
				printf("\nPostorder traversal is : ");
				postorder_using_rc(root);
				printf("\n");
				break;		
			case 9:
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
/*****binary search tree creation without recursion [start]......*****/
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
/*****binary search tree creation without recursion [stop]......*****/

/*****binary search tree creation using recursion [start].....*****/
bstree *create_bstree_using_rc(bstree *root)
{
	void insert_bstree_using_rc(bstree *, bstree *);
	bstree *new_node;
	int x;
	printf("(Enter[-999]for stop insertion process) Enter another data: ");
	scanf("%d",&x);
	if(x==-999)
		return root;
 	new_node=get_node(x);
 	insert_bstree_using_rc(root,new_node);
	create_bstree_using_rc(root);
}
void insert_bstree_using_rc(bstree *root, bstree *new_node)
{
	if(new_node->data<root->data )
	{
		if(root->left==NULL)
			root->left=new_node;
		else
			insert_bstree_using_rc(root->left,new_node);
	}
	else
	{
		if(root->right==NULL)
			root->right=new_node;
		else
			insert_bstree_using_rc(root->right,new_node);	
	}
}
/*****binary search tree creation using recursion [stop].....*****/
int bin_search_wt_rc(bstree *root, int x)
{
	bstree *p;
	p=root;
	while (p!=NULL)
	{
		if(p->data==x)
			return 1;
		if(x<p->data)	
		  	p=p->left;
		else
		  	p=p->right; 	
	}
	return -1;
}
int bin_search_using_rc(bstree *root, int x)
{
	if (root==NULL)
		return -1;
	if(root->data==x)
		return 1;
	if(x<root->data)	
	  return (bin_search_using_rc(root->left,x));
	else
	  return(bin_search_using_rc(root->right,x));
}
bstree *del_node(bstree *root, int x)
{
	bstree *p,*q,*r,*s;
	if(root==NULL)
	{
		printf("\nBinary search tree does not exist\n");
		return root;
	}
	p=root;
	q=root;
	while(q!=NULL&&q->data!=x)          //searching for the position of the searched data
	{
		p=q;
		if(x<q->data)
			q=q->left;
		else
			q=q->right;	
	}
	if(q==NULL)
	{
		printf("value not found\n");
		return root;
	}
	if(q->left==NULL&&q->right==NULL&&p->left==q)      //if deleted node [q] has no child and it also be a left child of a parrent node [p]
		p->left=NULL;
	else if(q->left==NULL&&q->right==NULL&&p->right==q)	//if deleted node [q] has no child and it also be a right child of a parrent node [p]
		p->right=NULL;
	else if(q->left==NULL)  //deleted node [q] has only right child and it also be a child of a parrent node [p]
	{
		if(p==q)    // if left subtree is not exist[ony present root and right subtree]
		{
			root=q->right;
			free(q);
			return root;
		}
		else if(p->right==q)  //deleted node [q] has only right child and it also be the right child of a parrent node [p]
			p->right=q->right;
		else                 //deleted node [q] has only right child and it also be the left child of a parrent node [p]
			p->left=q->right;	
	}	
	else if(q->right==NULL)  //deleted node [q] has only left child and it also be a child of a parrent node [p]
	{
		if(p==q)    // if right subtree is not exist[ony present root and left subtree]
		{
			root=q->left;
			free(q);
			return root;
		}
		else if(p->left==q)  //deleted node [q] has only left child and it also be the left child of a parrent node [p]
			p->left=q->left;
		else
			p->right=q->left;	//deleted node [q] has only left child and it also be the right child of a parrent node [p]
	}
	else  //deleted node [q] has two child and it also be a child of a parrent node [p]
	{
		// find out the inorder successor of the deleted node [q]
		r=q->right;
		s=q->right;
		while(s->left!=NULL)
		{
			r=s;
			s=s->left;
		}
		if(r==s)  //if the right node of the deleted node [q] is the inorder successor [s] then
			s->left=q->left;		
		else  //the left and right node of the deleted node will be connected with the inorder successor [s]
		{
			r->left=s->right;
			s->left=q->left;
			s->right=q->right;
		}
		if(p->left==q)  //if deleted node [q] is present in the left side of the parrent node [p] then connect the inorder successor [s] in the left side of parrent node [p]
			p->left=s;	
		else
			p->right=s;  //if deleted node [q] is present in the right side of the parrent node [p] then connect the inorder successor [s] in the right side of parrent node [p]	
		if(p==q)   //if delete root node then rearrange the root node
			root=s;
	}
	free(q);
	return root;
}
void preorder_using_rc(bstree *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder_using_rc(root->left);
		preorder_using_rc(root->right);
	}
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
void postorder_using_rc(bstree *root)
{
	if(root!=NULL)
	{
		postorder_using_rc(root->left);
		postorder_using_rc(root->right);
		printf("%d ",root->data);
	}
}
