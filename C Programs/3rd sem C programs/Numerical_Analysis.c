#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct pnode
{
	double coef;
	int exp;
	struct pnode *next;
}pnode;

typedef struct node1
{
	double a1,a2,a3,a4,a5;
	struct node1 *next;
}node1;

int dis_case1();
int dis_case2();
int dis_case3();
int dis_case4();
int dis_case5();
pnode *head;
node1 *head1;
pnode *get_pnode(double , int );	
pnode *create_poly(pnode *);
void display_poly(pnode *);
double f(double );
double fd(double );
double fdd(double );
double bisection_method();
double newton_raphson_method();
float** create_matrix(int *);
void display_matrix(float **,int );
void gauss_ellimination(float **, int );
void gauss_jordon(float **, int );
void gauss_seidel(float **,int );
void gauss_jacobi(float **,int );
void inverse_matrix();
int simpson(float **,float **,float *);
void disp_s_1_by_3(float *,float *,float *,int );

int main()
{
	int x,y,z;
	int c,i,j;
	float **a,**b,*q,*p,s[4];
	double r;
	do
	{
		system("cls");  //system("clear");
		printf("------------------------------------------\n");
		printf("|          |Numerical Analysis|          |\n");
		printf("------------------------------------------\n");
		printf("|1.INTERPOLATION POLYNOMIAL.             |\n");
		printf("|2.SOLUTIONS OF NON-LINEAR EQUATIONS.    |\n");
		printf("|3.SOLUTION OF DIFFERENTIAL EQUATIONS.   |\n");
		printf("|4.INTEGRATIONS.                         |\n");
		printf("|5.SYSTEM OF LINEAR EQUATIONS.           |\n");
		printf("|6.EXIT FROM THE PROGRAM.                |\n");
		printf("------------------------------------------\n");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
					system("cls");
					
					
					
					y=0;
					while(y!=4)	
					{
						system("cls"); //system("clear");
						y=dis_case1();
						switch(y)
						{
							case 1: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|    |NEWTON'S FORWARD INTERPOLATION|    |\n");	
									printf("------------------------------------------\n");
									
						
									
									break;
							case 2: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|    |NEWTON'S BACKWARD INTERPOLATION|    |\n");	
									printf("------------------------------------------\n");
									
									
									break;
							case 3: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|       |LAGRANGE'S INTERPOLATION|        |\n");	
									printf("------------------------------------------\n");
									
									
									
									break;
							case 4:
									break;
							default:
									printf("\nWRONG CHOICE...\n\n");
									getchar();
									printf("PRESS ANY KEY TO CONTINUE...\n");
									getchar();						
						}
					}
					break;
			case 2:
					system("cls"); //system("clear");
					head=create_poly(head);
					y=0;
					while(y!=5)	
					{
						system("cls");
						printf("The polinomial is : ");
						display_poly(head);
						printf("\n");
						y=dis_case2();
						switch(y)
						{
							case 1: 
									system("cls"); //system("clear");
									printf("The polinomial is : ");
									display_poly(head);
									printf("\n");
									printf("------------------------------------------\n");
									printf("|            |BISECTION METHOD|            |\n");	
									printf("------------------------------------------\n");
									r=bisection_method();
									printf("\nIter\tAn(+ve)\t\tBn(-ve)\t\tXn+1=(An+Bn)/2\t f(Xn+1)\n");
									printf("\n-----------------------------------------------------------------\n\n");
									while(head1!=NULL)
									{
										printf("%2.0lf\t%+lf\t%+lf\t%+lf\t%+lf\n",head1->a1,head1->a2,head1->a3,head1->a4,head1->a5);
										head1=head1->next;	
									}
									printf("\n\n\t\t\t The root is: X = %f\n\n\n",r);
									getchar();
									printf("PRESS ANY KEY TO CONTINUE...");
									getchar();
									break;
							case 2: 
									system("cls"); //system("clear");
									printf("The polinomial is : ");
									display_poly(head);
									printf("\n");
									printf("------------------------------------------\n");
									printf("|         |NEWTON-RAPHSON METHOD|         |\n");	
									printf("------------------------------------------\n");
									r=newton_raphson_method();
									printf("\nIter\tXn\t\tf(Xn)\t\tf'(Xn)\t\tHn\t\tXn+1=Xn+Hn\n");
  									printf("----------------------------------------------------------------------------------\n");
									c=0;
									while(head1!=NULL)
									{
										printf("%2d\t%+lf\t%+lf\t%+lf\t%+lf\t%+lf\n",++c,head1->a1,head1->a2,head1->a3,head1->a4,head1->a5);
										head1=head1->next;	
									}
									printf("\n\n\t\t\t The root is: X = %f\n\n\n",r);
									getchar();
									printf("PRESS ANY KEY TO CONTINUE...");
									getchar();
									
									break;
							case 3: 
									system("cls"); //system("clear");
									printf("The polinomial is : ");
									display_poly(head);
									printf("\n");
									printf("------------------------------------------\n");
									printf("|             |SECAND METHOD|             |\n");	
									printf("------------------------------------------\n");
									
									
									
									break;
							case 4: 
									system("cls"); //system("clear");
									printf("The polinomial is : ");
									display_poly(head);
									printf("\n");
									printf("------------------------------------------\n");
									printf("|          |REGULA-FALSI METHOD|          |\n");	
									printf("------------------------------------------\n");
									
									
									
									break;		
							case 5:
									break;
							default:
									printf("\nWRONG CHOICE...\n\n");
									getchar();
									printf("PRESS ANY KEY TO CONTINUE...\n");
									getchar();						
						}
					}
					break;
			case 3:
					system("cls");
					
					
					y=0;
					while(y!=4)	
					{
						system("cls"); //system("clear");
						y=dis_case3();
						switch(y)
						{
							case 1: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|     |RUNGE-KUTTA METHOD 2ND ORDER|      |\n");	
									printf("------------------------------------------\n");
									
									
									
									break;
							case 2: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|     |RUNGE-KUTTA METHOD 4TH ORDER|     |\n");	
									printf("------------------------------------------\n");
									
									
									break;
							case 3: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|             |EULER METHOD|              |\n");	
									printf("------------------------------------------\n");
									
									
									
									break;
							case 4:
									break;
							default:
									printf("\nWRONG CHOICE...\n\n");
									getchar();
									printf("PRESS ANY KEY TO CONTINUE...\n");
									getchar();						
						}
					}
					break;
			case 4:
					system("cls");
					head=create_poly(head);
					y=0;
					while(y!=3)	
					{
						system("cls");
						printf("The polinomial is : ");
						display_poly(head);
						printf("\n\n");
						y=dis_case4();
						switch(y)
						{
							case 1: 
									system("cls"); //system("clear");
									printf("The polinomial is : ");
									display_poly(head);
									printf("\n\n");
									printf("------------------------------------------\n");
									printf("|       |SIMPSON'S ONE-THIRD RULE|        |\n");	
									printf("------------------------------------------\n");
									c=simpson(&q,&p,s);
									disp_s_1_by_3(q,p,s,c);
									getchar();
									printf("\nPRESS ANY KEY TO CONTINUE...");
									getchar();
									break;
							case 2: 
									system("cls"); //system("clear");
									printf("The polinomial is : ");
									display_poly(head);
									printf("\n\n");
									printf("------------------------------------------\n");
									printf("|            |TRAPEZOIDAL RULE|             |\n");	
									printf("------------------------------------------\n");
									
									
									break;
							case 3:
									break;
							default:
									printf("\nWRONG CHOICE...\n\n");
									getchar();
									printf("PRESS ANY KEY TO CONTINUE...\n");
									getchar();						
						}
					}
					break;
			case 5:
					system("cls");
					b=create_matrix(&c);
					a=(float **)malloc(sizeof(float)*(c+1));
					for(i=0;i<=c;i++)
						a[i]=(float *)malloc(sizeof(float)*(c+1));
					y=0;
					while(y!=6)	
					{
						system("cls");  //system("clear");
						for(i=0;i<=c;i++)
						{
							for(j=0;j<=c;j++)
								a[i][j]=b[i][j];
						}
						display_matrix(a,c);
						y=dis_case5();
						switch(y)
						{
							case 1: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|            |GAUSS-ELIMINATION|          |\n");	
									printf("------------------------------------------\n");
									gauss_ellimination(a,c);
									getchar();
									printf("\nPRESS ANY KEY TO CONTINUE...");
									getchar();
									break;
							case 2: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|              |GAUSS-JORDON|            |\n");	
									printf("------------------------------------------\n\n");
									gauss_jordon(a,c);
									getchar();
									printf("\nPRESS ANY KEY TO CONTINUE...");
									getchar();
									break;
							case 3: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|              |GAUSS-SEIDEL|             |\n");	
									printf("------------------------------------------\n");
									gauss_seidel(a,c);
									getchar();
									printf("\nPRESS ANY KEY TO CONTINUE...");
									getchar();
									break;
							case 4: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|              |GAUSS-JACOBI|             |\n");	
									printf("------------------------------------------\n");
									gauss_jacobi(a,c);
									getchar();
									printf("\nPRESS ANY KEY TO CONTINUE...");
									getchar();
									break;	
							case 5: 
									system("cls"); //system("clear");
									printf("------------------------------------------\n");
									printf("|             |INVERSE MATRIX|            |\n");	
									printf("------------------------------------------\n");
									inverse_matrix();
									getchar();
									printf("\nPRESS ANY KEY TO CONTINUE...");
									getchar();
									break;			
							case 6:
									break;
							default:
									printf("\nWRONG CHOICE...\n\n");
									getchar();
									printf("PRESS ANY KEY TO CONTINUE...\n");
									getchar();						
						}
					}
					break;
			case 6:	
					exit(0);
			default:
			    	printf("\nWRONG CHOICE...\n\n");
					getchar();
					printf("PRESS ANY KEY TO CONTINUE...\n");
					getchar();	
        }
	}while(1);
}

int dis_case1()
{
	int x;
	printf("------------------------------------------\n");
	printf("|       |INTERPOLATION POLYNOMIAL|       |\n");
	printf("------------------------------------------\n");
	printf("|1.NEWTON'S FORWARD INTERPOLATION.       |\n");
	printf("|2.NEWTON'S BACKWARD INTERPOLATION.      |\n");
	printf("|3.LAGRANGE'S INTERPOLATION.             |\n");
	printf("|4.BACK [ <- ].                          |\n");
	printf("------------------------------------------\n");
	printf("\nENTER YOUR CHOICE: ");
	scanf("%d",&x);
	return x;
}

int dis_case2()
{
	int x;
	printf("------------------------------------------\n");
	printf("|  |SOLUTIONS OF NON-LINEAR EQUATIONS|   |\n");
	printf("------------------------------------------\n");
	printf("|1.BISECTION METHOD.                     |\n");
	printf("|2.NEWTON-RAPHSON METHOD.                |\n");
	printf("|3.SECAND METHOD.                        |\n");
	printf("|4.REGULA-FALSI METHOD.                  |\n");
	printf("|5.BACK [ <- ].                          |\n");
	printf("------------------------------------------\n");
	printf("\nENTER YOUR CHOICE: ");
	scanf("%d",&x);
	return x;
}

int dis_case3()
{
	int x;
	printf("------------------------------------------\n");
	printf("|  |SOLUTION OF DIFFERENTIAL EQUATIONS|  |\n");
	printf("------------------------------------------\n");
	printf("|1.RUNGE-KUTTA METHOD 2ND ORDER.         |\n");
	printf("|2.RUNGE-KUTTA METHOD 4TH ORDER.         |\n");
	printf("|3.EULER METHOD.                         |\n");
	printf("|4.BACK [ <- ].                          |\n");
	printf("------------------------------------------\n");
	printf("\nENTER YOUR CHOICE: ");
	scanf("%d",&x);
	return x;
}

int dis_case4()
{
	int x;
	printf("------------------------------------------\n");
	printf("|             |INTEGRATIONS|             |\n");
	printf("------------------------------------------\n");
	printf("|1.SIMPSON'S ONE-THIRD RULE.             |\n");
	printf("|2.TRAPEZOIDAL RULE.                     |\n");
	printf("|3.BACK [ <- ].                          |\n");
	printf("------------------------------------------\n");
	printf("\nENTER YOUR CHOICE: ");
	scanf("%d",&x);
	return x;
}

int dis_case5()
{
	int x;
	printf("------------------------------------------\n");
	printf("|      |SYSTEM OF LINEAR EQUATIONS|      |\n");
	printf("------------------------------------------\n");
	printf("|1.GAUSS-ELIMINATION.                    |\n");
	printf("|2.GAUSS-JORDON.                         |\n");
	printf("|3.GAUSS-SEIDEL.                         |\n");
	printf("|4.GAUSS-JACOBI.                         |\n");
	printf("|5.INVERSE MATRIX.                       |\n");
	printf("|6.BACK [ <- ].                          |\n");
	printf("------------------------------------------\n");
	printf("\nENTER YOUR CHOICE: ");
	scanf("%d",&x);
	return x;
}

pnode *get_pnode(double x, int y)
{
	pnode*p;
	p=(pnode*)malloc(sizeof(pnode));
	p->coef=x;
	p->exp=y;
	p->next=NULL;
	return p;
}
node1 *get_node1(double b1,double b2,double b3,double b4,double b5)
{
	node1 *p;
	p=(node1 *)malloc(sizeof(node1));
	p->a1=b1;
	p->a2=b2;
	p->a3=b3;
	p->a4=b4;
	p->a5=b5;
	p->next=NULL;
	return p;
}
pnode *create_poly(pnode *head)
{
	pnode *p,*q;
	int y;
	double x;
	char ch='y';
	head=NULL; 
	while(ch=='y'||ch=='Y')
	{
		printf("Enter the coefficient: ");
		scanf("%lf",&x);
		printf("\nEnter the exponent: ");
		scanf("%d",&y);
		p=get_pnode(x,y);	
		if(head==NULL)
		  head=p;
		else
		  q->next=p;
		q=p;
		printf("\nContinue adding more terms ?(y/n): ");
		fflush(stdin);	
		scanf("%c",&ch);
		printf("\n");
	}
  	return head;
}

void display_poly(pnode *head)
{
	pnode*p;
	if(head==NULL)
	printf("\nLink list not exist\n\n");
	p=head;
	printf("%.2lfX^%d",p->coef,p->exp); 
	p=p->next;
	while(p!=NULL)
	{
		if(p->coef<0)
		  printf("%.2lfX^%d",p->coef,p->exp);
		else
		  printf("+%.2lfX^%d",p->coef,p->exp);
		p=p->next;
	}
}

double f(double x)
{
	double cal=0;
	pnode *p;
	p=head;
	while(p!=NULL)
	{
		cal=cal+(p->coef*pow(x,p->exp));
		p=p->next;
	}
	return cal;
}

double fd(double x)
{
	double cal=0;
	pnode *p;
	p=head;
	while(p!=NULL)
	{
		if(p->exp<1)
			cal=cal+0;
		else	
			cal=cal+(p->coef*p->exp*pow(x,p->exp-1));
		p=p->next;
	}
	return cal;
}

double fdd(double x)
{
	double cal=0;
	pnode *p;
	p=head;
	while(p!=NULL)
	{
		if(p->exp<2)
			cal=cal+0;
		else
			cal=cal+(p->coef*p->exp*(p->exp-1)*pow(x,p->exp-2));
		p=p->next;		
	}
	return cal;
}

double bisection_method()
{
	double a,b,x,y,err;
	int d,n=0;
	node1 *p,*q;
	do
	{
		printf("\nEnter the lower limit: ");
		scanf("%lf",&a);
		printf("\nEnter the upper limit: ");
		scanf("%lf",&b);
		if(f(a)*f(b)<0)
			break;
		else	
			printf("\n\nRoot does not exists between %.2lf and %.2lf\n\n",a,b);
	}while(1);
	if(f(a)<0.0&&f(b)>0.0)
	{
		y=b;
		b=a;
		a=y;
	}
	printf("\nEnter the correction upto decimal place: ");
  	scanf("%d",&d);
  	err=(5.0/pow(10,d));
 	x=0;
	do
	{
		y=x;
		x=(a+b)/2;
		p=get_node1(++n,a,b,x,f(x));
		if(head1==NULL)
			head1=p;
		else
			q->next=p;
		q=p;		
		if(f(x)>0)
			a=x;
		else
			b=x;
	}while(fabs(x-y)>=err);
	return x;
}

double newton_raphson_method()
{
	double h,x,y,err;
	node1 *p,*q;
	int n=0,d;
 	do
  	{
		printf("\nEnter an approximate root: ");
		scanf("%lf",&x);
		if(fabs(f(x)*fdd(x))<(fd(x)*fd(x)))
			break;
		else
			printf("\nWrong value entered!!!try again...\n");
	}while(1);
	printf("\nEnter the correction upto decimal place: ");
  	scanf("%d",&d);
  	err=(5.0/pow(10,d));
  	y=x;
	h=f(x)/fd(x);
	x=x-h;
	p=get_node1(y,f(y),fd(x),h,x);
	head1=p;
	q=p;
	while(fabs(x-y)>=err)
	{
		y=x;
		h=f(x)/fd(x);
		x=x-h;
		p=get_node1(y,f(y),fd(x),h,x);
		q->next=p;
		q=p;
	}
	return x;
}
float** create_matrix(int *c)
{
	int i,j,k,n;
	float **a,r;
	do
	{
		printf("Enter the number of equations: ");
		scanf("%d",&n);
		if(n>0)
			break;
	}while(1);
	a=(float **)malloc(sizeof(float)*(n+1));
	for(i=0;i<=n;i++)
		a[i]=(float *)malloc(sizeof(float)*(n+1));
	printf("\nEnter co-efficient matrix [A] row wise:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\na[%d][%d]= ",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter column matrix [B] row wise:\n");
	for(i=0,j=n;i<n;i++)
	{
		printf("\nb[%d]= ",i+1);
		scanf("%f",&a[i][j]);
	}
	*c=n;
	return a;
}
void display_matrix(float **a,int n)
{
	int i,j;
	printf("| The matrix is |\n\n");
	for(i=0;i<n;i++)
	{	
		printf("|  ");
		for(j=0;j<n;j++)
 		{
		 	printf("%+5.2f  ",a[i][j]);
   		}
   		printf("|\t| %+5.2f |\n",a[i][j]);
	}
	printf("\n");
		
}

void gauss_ellimination(float **a,int n)
{
	int i,j,k;
	float *x,r;
	x=(float *)malloc(sizeof(float)*n);
	for(k=0;k<n-1;k++)
	{
		for(i=k+1;i<n;i++)
		{
			r=a[i][k]/a[k][k];
			for(j=0;j<=n;j++)
			{
				a[i][j]=a[i][j]-r*a[k][j];
			}
		}
		printf("\nStep %d:-\n\n",k+1);
		for(i=0;i<n;i++)
    	{	
    		printf("| ");
    		for(j=0;j<n;j++)
	 		{
			 	printf("%+5.2f ",a[i][j]);
       		}
       		printf("|\t| %+5.2f |\n",a[i][j]);
		}
		printf("\n");
	}
	x[n-1]=a[n-1][n]/a[n-1][n-1];
	for(j=n-2;j>=0;j--)
	{
	    x[j]=a[j][n];
	    for(i=n-1;i>j;i--)
	    {
	    	x[j]=x[j]-a[j][i]*x[i];
	    }
	    x[j]=x[j]/a[j][j];
	}
	printf("\nThe solution is:-\n");
	for(i=0;i<n;i++)
	   printf("\t\t  X[%d] = %5.2f\n",i+1,x[i]); 
	printf("\n");   
}

void gauss_jordon(float **a,int n)
{
	int i,j,k;
	float *x,r;
	x=(float *)malloc(sizeof(float)*n);
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(i==k)
				continue;
			r=a[i][k]/a[k][k];
			for(j=0;j<=n;j++)
			{
				a[i][j]=a[i][j]-r*a[k][j];
			}
		}
		printf("\nStep %d:-\n\n",k+1);
		for(i=0;i<n;i++)
    	{	
    		printf("| ");
    		for(j=0;j<n;j++)
	 		{
			 	printf("%+5.2f ",a[i][j]);
       		}
       		printf("|\t| %+5.2f |\n",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		x[i]=a[i][n]/a[i][i];
		a[i][i]=a[i][i]/a[i][i];
	}
	printf("\nStep %d:-\n\n",k+1);
	for(i=0;i<n;i++)
	{	
		printf("| ");
		for(j=0;j<n;j++)
 		{
		 	printf("%+5.2f ",a[i][j]);
   		}
   		printf("|\t| %+5.2f |\n",x[i]);
	}
	printf("\n");
	printf("\nThe solution is:-\n");
	for(i=0;i<n;i++)
	   printf("\t\t  X[%d] = %5.2f\n",i+1,x[i]); 
	printf("\n");  
}


void gauss_seidel(float **a,int n)
{
	int i,j,k,d,flag=0,iteration=0;
	float *x,*y,err,s;
	x=(float *)malloc(sizeof(float)*n);
	y=(float *)malloc(sizeof(float)*n);
	printf("\nEnter the correction upto decimal place: ");
  	scanf("%d",&d);
  	err=(5.0/pow(10,d));
	for(i=0;i<n;i++)
	{
		s=0.0;
		for(j=0;j<n;j++)
		{
			if(i==j)
				continue;
			s=s+(fabs(a[i][j]));
		}
		if((fabs(a[i][i]))<s)
		{
			printf("\nThe entered system of linear equeation is not diagonaly dominant.\n");
			return;
		}
	}
	for(i=0;i<n;i++)
    {
	    x[i]=0.0;
	    y[i]=0.0;
    }
    printf("\nItr\t");
    for(i=0;i<n;i++)
    	printf("  X[%d]\t\t",i+1);
    printf("\n");	
	do
	{
	    iteration++;
	    for(i=0;i<n;i++)
	    {
	       x[i]=a[i][n];
	       for(j=0;j<n;j++)
		    {
		      	if(i==j)
					continue;
		        x[i]=x[i]-a[i][j]*x[j];
		    }
       		x[i]=x[i]/a[i][i];
	    }
		for(i=0;i<n;i++)
	    {
	      	flag=0;
	      	if((fabs(x[i]-y[i]))>err)
		    {
		        flag=1;
		        for(j=0;j<n;j++)
		        {
				    y[j]=x[j];
				}
		        break;
		    }
	    }
	   	printf("\n%2d\t",iteration);
	    for(j=0;j<n;j++)  
			printf("%f\t",x[j]);
   	}while(flag==1);
	printf("\n\nThe solution is:-\n");
	for(i=0;i<n;i++)
	   printf("\t\t  X[%d] = %5.2f\n",i+1,x[i]); 
	printf("\n"); 
}

void gauss_jacobi(float **a,int n)
{
	int i,j,k,d,flag=0,iteration=0;
	float *x,*y,err,s;
	x=(float *)malloc(sizeof(float)*n);
	y=(float *)malloc(sizeof(float)*n);
	printf("\nEnter the correction upto decimal place: ");
  	scanf("%d",&d);
  	err=(5.0/pow(10,d));
	for(i=0;i<n;i++)
	{
		s=0.0;
		for(j=0;j<n;j++)
		{
			if(i==j)
				continue;
			s=s+(fabs(a[i][j]));
		}
		if((fabs(a[i][i]))<s)
		{
			printf("\nThe entered system of linear equeation is not diagonaly dominant.\n");
			return;
		}
	}
	for(i=0;i<n;i++)
    {
	    x[i]=0.0;
	    y[i]=0.0;
    }
    printf("\nItr\t");
    for(i=0;i<n;i++)
    	printf("  X[%d]\t\t",i+1);
    printf("\n");	
	do
	{
	    iteration++;
	    for(i=0;i<n;i++)
	    {
	       x[i]=a[i][n];
	       for(j=0;j<n;j++)
		    {
		      	if(i==j)
					continue;
		        x[i]=x[i]-a[i][j]*y[j];
		    }
       		x[i]=x[i]/a[i][i];
	    }
		for(i=0;i<n;i++)
	    {
	      	flag=0;
	      	if((fabs(x[i]-y[i]))>err)
		    {
		        flag=1;
		        for(j=0;j<n;j++)
		        {
				    y[j]=x[j];
				}
		        break;
		    }
	    }
	   	printf("\n%2d\t",iteration);
	    for(j=0;j<n;j++)  
			printf("%f\t",x[j]);
   	}while(flag==1);
	printf("\n\nThe solution is:-\n");
	for(i=0;i<n;i++)
	   printf("\t\t  X[%d] = %5.2f\n",i+1,x[i]); 
	printf("\n"); 
}

void inverse_matrix()
{
	float **a,**b,r;
	int i,j,k,n;
	printf("\nEnter the order of the square matrix: ");
	scanf("%d",&n);
	a=(float **)malloc(sizeof(float)*n);
	for(i=0;i<n;i++)
		a[i]=(float *)malloc(sizeof(float)*n);
	b=(float **)malloc(sizeof(float)*n);
	for(i=0;i<n;i++)
		b[i]=(float *)malloc(sizeof(float)*n);	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\na[%d][%d]=",i+1,j+1);
			scanf("%f",&a[i][j]);
			if(i==j)
				b[i][j]=1.0;
			else
				b[i][j]=0.0;
		}
		printf("\n");
	}
	printf("\n\nThe main matrix is:-\n\n");
	for(i=0;i<n;i++)
	{
		printf("|  ");
		for(j=0;j<n;j++)
		{
			printf("%5.2f  ",a[i][j]);
		}
		printf("|\n");
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(k==i)
				continue;
			r=a[i][k]/a[k][k];
			for(j=0;j<n;j++)
			{
				a[i][j]=a[i][j]-r*a[k][j];
				b[i][j]=b[i][j]-r*b[k][j];
			}
		}
		//Steps display start. [optional]
		printf("\nStep %d:-\n\n",k+1);
		for(i=0;i<n;i++)
    	{	
    		printf("|  ");
    		for(j=0;j<n;j++)
	 		{
			 	printf("%+5.2f  ",a[i][j]);
       		}
       		printf(" |\t");
       		printf("|  ");
    		for(j=0;j<n;j++)
	 		{
			 	printf("%+5.2f  ",b[i][j]);
       		}
       		printf(" |\n");
		}
		printf("\n");	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=b[i][j]/a[i][i];
		}
		a[i][i]=a[i][i]/a[i][i];
	}
	printf("\nStep %d:-\n\n",k+1);
	for(i=0;i<n;i++)
	{	
		printf("|  ");
		for(j=0;j<n;j++)
 		{
		 	printf("%+5.2f  ",a[i][j]);
   		}
   		printf(" |\t");
   		printf("|  ");
		for(j=0;j<n;j++)
 		{
		 	printf("%+5.2f  ",b[i][j]);
   		}
   		printf("  |\n");
	}
	printf("\n\n\nThe inverse matrix is:-\n\n");
	for(i=0;i<n;i++)
	{
		printf("| ");
		for(j=0;j<n;j++)
		{
			printf("%+5.2f  ",b[i][j]);
		}
		printf("|\n");
	}
	printf("\n");
}
int simpson(float **q,float **p,float *s)
{
	float a,b,h,*x,*y;
	int n,i;
	printf("\nEnter the lower limit: ");
	scanf("%f",&a);
	printf("\nEnter the upper limit: ");
	scanf("%f",&b);
	s[1]=0.0;
	s[2]=0.0;
	do
	{
		printf("\nEnter the number of sub intervals: ");
		scanf("%d",&n);
		if(n%2!=0)
			printf("\nNumber of sub intervals should be even.\n");
		else
			break;	
	}while(1);
	x=(float *)malloc(sizeof(float)*(n+1));
	y=(float *)malloc(sizeof(float)*(n+1));
	h=(b-a)/n;
	x[0]=a;
	x[n]=b;
	y[0]=f(x[0]);
	y[n]=f(x[n]);
	s[0]=y[0]+y[n];
	for(i=1;i<n;i+=2)
	{	
		x[i]=x[0]+i*h;
	 	y[i]=f(x[i]);
	 	s[1]=s[1]+y[i];
	}
	for(i=2;i<n;i+=2)
	{ 
		x[i]=x[0]+i*h;
		y[i]=f(x[i]);
		s[2]=s[2]+y[i];
	}
	s[3]=(h/3.0)*(s[0]+(4*s[1])+(2*s[2]));
	(*q)=x;
	(*p)=y;
	return n;
}
void disp_s_1_by_3(float *q,float *p,float *s,int c)
{
	int i;
	printf("\nComputation table:-\n\n");
	printf("------------------------------------------------------------------------------------------");
	printf("\n|  i  |\t| Xi=Xo+ih |\t| Yi=f(x),i=0,%d |\t|Yi=f(x),i=1,3,..|\t|Yi=f(x),i=2,4,..|\n",c);
	printf("------------------------------------------------------------------------------------------\n");
	for(i=0;i<=c;i++)
	{
		printf("| %2d  |\t|   %5.5f   |",i,q[i]);
		if(i==0||i==c)
			printf("\t|     %5.5f\t |",p[i]);
		else
			printf("\t|\t\t |");
		if(i==0||i==c)
		{
			printf("\t|\t\t |\t|\t\t |\n");
			continue;
		}
		if(i%2==0)
			printf("\t|\t\t |\t|     %5.5f\t |\n",p[i]);
		else
			printf("\t|     %5.5f\t |\t|\t\t |\n",p[i]);	
	}
	printf("------------------------------------------------------------------------------------------");
	printf("\n| sum |\t| \t   |\t|     %5.5f\t |\t|     %5.5f\t |\t|     %5.5f\t |\n",s[0],s[1],s[2]);
	printf("------------------------------------------------------------------------------------------\n");
	printf("\nThe result of Simpson's 1/3 rule is = %5.5f\n\n",s[3]);
}
