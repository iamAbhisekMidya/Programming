#include<stdio.h>
#include<stdlib.h>
struct complex_no
{
	int x;
	int y;
}typedef complex;
void disp(complex t)
{
	if(t.y<0)
		printf("\nResult is %d - i%d\n\n",t.x,-t.y);
	else
		printf("\nResult is %d + i%d\n\n",t.x,t.y);
}
complex add(complex p,complex q)
{
	complex t;
	t.x=p.x+q.x;
	t.y=p.y+q.y;
	return t;
}
complex sub(complex p,complex q)
{
	complex t;
	t.x=p.x-q.x;
	t.y=p.y-q.y;
	return t;
}
complex multi(complex p,complex q)
{
	complex t;
	t.x=p.x*q.x-p.y*q.y;
	t.y=p.x*q.y+p.y*q.x;
	return t;
}
void dive(complex p,complex q)
{
	float t1,t2;
	t1=(float)(p.x*q.x+p.y*q.y)/(q.x*q.x+q.y*q.y);
	t2=(float)(p.y*q.x-p.x*q.y)/(q.x*q.x+q.y*q.y);
	if(t2<0.0)
		printf("result is %.2f-i%.2f\n\n",t1,-t2);                      //     %.nf  -> n= number of term after point.
	else
		printf("result is %.2f+i%.2f\n\n",t1,t2);
}
int main()
{
	complex a,b,c;
	int ch;
	while(1)
	{
		printf("Choose 1 for addition of two complex number\n");
		printf("Choose 2 for subtraction of two complex number\n");
		printf("Choose 3 for multipication of two complex number\n");
		printf("Choose 4 for devition of two complex number\n");
		printf("Choose 5 for exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:  
			          printf("Enter the real part of the first complex number: ");
			          scanf("%d",&a.x);
			          printf("Enter the imaginary part of the first complex number: ");
			          scanf("%d",&a.y);
			          printf("Enter the real part of the secound complex number: ");
			          scanf("%d",&b.x);
			          printf("Enter the imaginary part of the secound complex number: ");
			          scanf("%d",&b.y);
			          c=add(a,b);
			          disp(c);
			          break;
			case 2:  
			          printf("Enter the real part of the first complex number: ");
			          scanf("%d",&a.x);
			          printf("Enter the imaginary part of the first complex number: ");
			          scanf("%d",&a.y);
			          printf("Enter the real part of the secound complex number: ");
			          scanf("%d",&b.x);
			          printf("Enter the imaginary part of the secound complex number: ");
			          scanf("%d",&b.y);
			          c=sub(a,b);
			          disp(c);
			          break;	
			case 3:
			          printf("Enter the real part of the first complex number: ");
			          scanf("%d",&a.x);
			          printf("Enter the imaginary part of the first complex number: ");
			          scanf("%d",&a.y);
			          printf("Enter the real part of the secound complex number: ");
			          scanf("%d",&b.x);
			          printf("Enter the imaginary part of the secound complex number: ");
			          scanf("%d",&b.y);
			          c=multi(a,b);
			          disp(c);
			          break;
			case 4:
			          printf("Enter the real part of the first complex number: ");
			          scanf("%d",&a.x);
			          printf("Enter the imaginary part of the first complex number: ");
			          scanf("%d",&a.y);
			          printf("Enter the real part of the secound complex number: ");
			          scanf("%d",&b.x);
			          printf("Enter the imaginary part of the secound complex number: ");
			          scanf("%d",&b.y);
			          dive(a,b);
			          break;
			case 5:
			          exit(0);
			default: 
			          printf("Wrong choice \n");
			
		}
	}
	return 1;
}
