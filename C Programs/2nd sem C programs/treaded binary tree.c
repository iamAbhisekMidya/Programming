#include<stdio.h>
#include<stdlib.h>
typedef struct tbt
{
	int data,th;
	struct tbt *left,*right;
}tbt;
int main()
{
	tbt *get_node(int );
	tbt *create_threaded_btree();
	void set_left(tbt *,tbt *);
	void set_right(tbt *,tbt *);
	void threaded_btree_inorder(tbt *);
	tbt *root=NULL;
	int x;
	do
	{
		printf("-----------------------------------------------------\n");
		printf("|              [THREADED BINARY TREE]                |\n");
		printf("-----------------------------------------------------\n");
		printf("|1.THREADED BINARY TREE [CREATION].                  |\n");
		printf("|2.THREADED BINARY TREE [INORDER TRAVERSING].        |\n");
		printf("|3.[EXIT] FROM THE PROGRAM.                          |\n");
		printf("-----------------------------------------------------\n");
		printf("Enter your choice ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				root=create_threaded_btree();
				printf("\n");
				break;
			case 2:
				printf("Inorder traversal is : ");
				threaded_btree_inorder(root);
				printf("\n");
				break;
			case 3:	
				exit(0);
			default :
			    printf("wrong choice\n\n");	
            }
	}while(1);
    return 1;
}
tbt *get_node(int x)
{
	tbt *p;
	p=(tbt*)malloc(sizeof(tbt));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	p->th=1;
	return p;
}
void set_left(tbt *p,tbt *r)
{
	p->left=r;
	r->right=p;
}
void set_right(tbt *p,tbt *r)
{
	r->right=p->right;
	p->right=r;
	p->th=0;
}
tbt *create_threaded_btree()
{
	void set_left(tbt *,tbt *);
	void set_right(tbt *,tbt *);
	tbt *root,*p,*q,*r;
	int x;
	printf("Enter the root element: ");
	scanf("%d",&x);
	root=get_node(x);
	printf("(Enter[-999]for stop insertion process) Enter another data: ");
	scanf("%d",&x);
	while(x!=-999)
	{
	 	p=root;
	 	q=root;
	 	while(q!=NULL)
	 	{
	 		p=q;
	 		if(x<q->data)
	 			q=q->left;
	 		else
		 	{
		 		if(q->th==1)
		 			q=NULL;
				else
					q=q->right;	 		
			}		
		}
		r=get_node(x);
		if(x<p->data)
			set_left(p,r);
		else
			set_right(p,r);	
	 	printf("(Enter[-999]for stop insertion process) Enter another data: ");
	 	scanf("%d",&x);
	}
	return root;
}
void threaded_btree_inorder(tbt *root)
{
	tbt *p;
	if(root==NULL)
	{
		printf("tree not exist");
		return;
	}
	p=root;
	while(p!=NULL)
	{
		while(p->left!=NULL)
			p=p->left;
		while(p!=NULL)
		{
			printf("%d ",p->data);
			if(p->th==0)
			{
				p=p->right;
				break;
			}
			else
				p=p->right;
		}
	}
}
