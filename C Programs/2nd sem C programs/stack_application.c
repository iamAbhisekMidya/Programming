#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	void display(char *);
	int precedence(char );
	void infix_to_postfix(char *,char *);
	void infix_to_prefix(char *,char *);
	int postfix_evaluation(char *);
	int prefix_evaluation(char *);
	char str0[100],str1[100],str2[100],str[100];
	int x,p,q;
	do
	{
		printf("----------------------------------------------\n");
		printf("|             [APPLICATION OF STACK]          |\n");
		printf("----------------------------------------------\n");
		printf("|1.Create string.                             |\n");
		printf("|2.Display string.                            |\n");
		printf("|3.Infix to postfix.                          |\n");
		printf("|4.Infix to prefix.                           |\n");
		printf("|5.Postfix evaluation.                        |\n");
		printf("|6.Prefix evaluation.                         |\n");
		printf("|7.Exit from the program.                     |\n");
		printf("----------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&x);
		printf("\n");
		switch(x)
		{
			case 1:
				printf("enter the string : ");
				fflush(stdin);
				gets(str0);
				break;
			case 2:
				display(str0);
				break;
			case 3:
				strcpy(str,str0);
				printf("\nthe postfix expression is :\n");
				infix_to_postfix(str,str1);
				puts(str1);
				printf("\n");
				break;
			case 4:
				strcpy(str,str0);
				printf("\nthe prefix expression is :\n");
				infix_to_prefix(str,str2);
				puts(str2);
				printf("\n");
				break;
			case 5:
				strcpy(str,str0);
				infix_to_postfix(str,str1);
				p=postfix_evaluation(str1);
				printf("\nthe postfix evaluation is:=%d\n",p);
				printf("\n");
				break;
			case 6:
				strcpy(str,str0);
				infix_to_prefix(str,str2);
				q=prefix_evaluation(str2);
				printf("\nthe prefix evaluation is:=%d\n",q);
				printf("\n");
				break;
			case 7:	
				exit(0);
			default :
			    printf("wrong choice\n\n");	
        }
	}while(1);
    return 1;
}
void display(char a[100])
{
	printf("the given array is: ");
	puts(a);
	printf("\n");  
}
int precedence(char x)
{
	if(x=='^'||x=='$')
		return 3;
	else if(x=='*'||x=='/')
		return 2;
	else if(x=='+'||x=='-')
		return 1;		
}
void infix_to_postfix(char q[100],char p[100])   //top1 for maintain stack and top2 for maintain postfix expression and [P] is the req postfix expression 
{
	int i,j,k,l,top1=-1,top2=-1;
	char stack[100];
	l=strlen(q);
	q[l]=')';
	q[l+1]='\0';
	top1=top1+1;
	stack[top1]='(';
	for(i=0;q[i]!='\0';i++)
	{
		if((q[i]>=48&&q[i]<=57)||(q[i]>=65&&q[i]<=90)||(q[i]>=97&&q[i]<=122))
		{
			if((q[i]>=48&&q[i]<=57))
			{
				top2=top2+1;
				p[top2]=q[i];
				if(q[i+1]=='^'||q[i+1]=='$'||q[i+1]=='*'||q[i+1]=='/'||q[i+1]=='+'||q[i+1]=='-'||q[i+1]=='('||q[i+1]==')')
				{
					top2++;
					p[top2]=',';
				}
			}
			else
			{
				top2=top2+1;
				p[top2]=q[i];
				top2++;
				p[top2]=',';
			}
		}
		if(q[i]=='(')
		{
			top1=top1+1;
			stack[top1]=q[i];
		}
		if(q[i]=='^'||q[i]=='$'||q[i]=='*'||q[i]=='/'||q[i]=='+'||q[i]=='-')
		{
			while((stack[top1]!='(')&&(precedence(stack[top1])>=precedence(q[i])))
			{
				top2=top2+1;
				p[top2]=stack[top1];
				top1=top1-1;
				top2++;
				p[top2]=',';
			}
			top1=top1+1;
			stack[top1]=q[i];
		}
		if(q[i]==')')
		{
			while(stack[top1]!='(')
			{
				top2=top2+1;
				p[top2]=stack[top1];
				top1=top1-1;
				top2++;
				p[top2]=',';
			}
			top1=top1-1;
		}
	}
	p[top2]='\0'; 
}
void infix_to_prefix(char q[100],char p[100])   //top1 for maintain stack and top2 for maintain prefix expression and [P] is the req prefix expression 
{
	int i,j,k,l,top1=-1,top2=-1;
	char stack[100];
	l=strlen(q);
	strrev(q);
	q[l]='(';
	q[l+1]='\0';
	l=strlen(q);
	top1=top1+1;
	stack[top1]=')';
	for(i=0;i<=l;i++)
	{
		if((q[i]>=48&&q[i]<=57)||(q[i]>=65&&q[i]<=90)||(q[i]>=97&&q[i]<=122))
		{
			if((q[i]>=48&&q[i]<=57)) // for integer
			{
				top2=top2+1;
				p[top2]=q[i];
				if(q[i+1]=='^'||q[i+1]=='$'||q[i+1]=='*'||q[i+1]=='/'||q[i+1]=='+'||q[i+1]=='-'||q[i+1]=='('||q[i+1]==')')
				{
					top2++;
					p[top2]=',';
				}
			}
			else      // for character 
			{
				top2=top2+1;
				p[top2]=q[i];
				top2++;
				p[top2]=',';
			}
		}		
		else if(q[i]==')')
		{
			top1=top1+1;
			stack[top1]=q[i];
		}
		else if(q[i]=='^'||q[i]=='$'||q[i]=='*'||q[i]=='/'||q[i]=='+'||q[i]=='-')
		{
			while((stack[top1]!=')')&&(precedence(q[i])<precedence(stack[top1])))
			{
				top2=top2+1;
				p[top2]=stack[top1];
				top1=top1-1;
				top2=top2+1;
				p[top2]=',';
			}
			top1=top1+1;
			stack[top1]=q[i];
		}
		else if(q[i]=='(')
		{
			while(stack[top1]!=')')
			{
				top2=top2+1;
				p[top2]=stack[top1];
				top1=top1-1;
				top2=top2+1;
				p[top2]=',';
			}
			top1=top1-1;
		}
	}
	top2=top2+1;
	p[top2]='\0';
	strrev(p);
	p[0]=' '; // for remove the first , bcz i reverse the string 
}
int postfix_evaluation(char q[100])    
{
	int stack[100],top=-1,i,j,a,b,s,t=0;
    j=strlen(q);
	for(i=0;i<=j;i++)
	{
		if(q[i]>=48&&q[i]<=57)
		{
			t=0;
			while(q[i]!=',')
			{
				t=t*10+q[i]-48;
				i++;
			}
			top++;
			stack[top]=t;
		}
		if(q[i]=='^'||q[i]=='$'||q[i]=='*'||q[i]=='/'||q[i]=='+'||q[i]=='-')
		{
			a=stack[top];
			top--;
			b=stack[top];
			top--;
			if(q[i]=='^'||q[i]=='$')
				s=pow(b,a);
			else if(q[i]=='*')	
				s=b*a;
			else if(q[i]=='/')	
				s=b/a;
			else if(q[i]=='+')	
				s=a+b;
			else if(q[i]=='-')
				s=b-a;
			top++;	
			stack[top]=s;
		}
	}
	return stack[top];
}
int prefix_evaluation(char q[100])
{
	int stack[100],top=-1,i,j,a,b,s,t=0,k=0;
    j=strlen(q);
    strrev(q);
	for(i=0;i<j;i++)
	{
		if(q[i]>=48&&q[i]<=57)
		{
			t=0;
			while(q[i]!=',')
			{
				t=t*10+q[i]-48;
				i++;
			}
			k=0;
			while(t!=0)
			{
				k=k*10+(t%10);
				t=t/10;
			}
			top++;
			stack[top]=k;
		}
		if(q[i]=='^'||q[i]=='$'||q[i]=='*'||q[i]=='/'||q[i]=='+'||q[i]=='-')
		{
			a=stack[top];
			top--;
			b=stack[top];
			top--;
			if(q[i]=='^'||q[i]=='$')
				s=pow(a,b);
			else if(q[i]=='*')	
				s=a*b;
			else if(q[i]=='/')	
				s=a/b;
			else if(q[i]=='+')	
				s=a+b;
			else if(q[i]=='-')
				s=a-b;
			top++;	
			stack[top]=s;
		}
	}
	return stack[top];
}
