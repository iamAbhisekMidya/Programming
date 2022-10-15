#include<stdio.h>
#include<stdlib.h>
#define maxlen 5
void insertion(int queue[],int *front,int *rear,int item)
{
	if((*front==0&&*rear==maxlen-1)||(*rear==*front-1))
	{
		printf("queue is overflow\n");
		return;
	}
	if(*front==-1&&*rear==-1)
	{
		*front=0;
		*rear=0;
	}
	else if(*rear==maxlen-1)
		*rear=0;
	else
		*rear=*rear+1;
	queue[*rear]=item;	
}
void deletion(int queue[],int *front,int *rear)
{
	if(*front==-1&&*rear==-1)
	{
		printf("queue is underflow\n");
		return;
	}
	printf("the deleted value is %d\n",queue[*front]);
	if(*rear==*front)
	{
		*front=-1;
		*rear=-1;
	}
	else if(*front==maxlen-1)
		*front=0;
	else	
		*front=*front+1;
}
void display(int queue[],int front,int rear)
{
	int i;
	if(front==-1&&rear==-1)
	{
		printf("no element present in the queue\n");
		return;
	}
	if(front>rear)
	{
		for(i=front;i<=maxlen-1;i++)	
		{
			printf("[%d] ",queue[i]);
		}
		for(i=0;i<=rear;i++)	
		{
			printf("[%d] ",queue[i]);
		}
   }
   else
   {
   		for(i=front;i<=rear;i++)	
		{
			printf("[%d] ",queue[i]);
		}
   }
   printf("\n");

}
int main()
{
	int queue[maxlen],ch,front=-1,rear=-1,item;
	do
	{
		printf("----------------------------------------------\n");
		printf("|              CIRCULAR QUEUE                |\n");
		printf("----------------------------------------------\n");
		printf("|1.display list                              |\n");
		printf("|2.insertion                                 |\n");
		printf("|3.deletion                                  |\n");
		printf("|4.exit_from_the_program                     |\n");
		printf("----------------------------------------------\n");
		printf("enter your choice ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				display(queue,front,rear);
				break;
			case 2:
				printf("enter the element which you want to insert ");
				scanf("%d",&item);
				insertion(queue,&front,&rear,item);
				break;
			case 3:
				deletion(queue,&front,&rear);
				break;
			case 4:	
				exit(0);
			default :
			    printf("wrong choice\n\n");	
        }
	}while(1);
    return 1;	
}

