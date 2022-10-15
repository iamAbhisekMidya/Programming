#include<stdio.h>
#include<stdlib.h>
struct point
{
	int x;
	int y;
};
struct line_segment
{
	struct point p,q;
};
int main()
{
	struct line_segment m,n;
	float g1,g2;
	printf("enter first point of first line ");
	scanf("%d%d",&m.p.x,&m.p.y);
	printf("enter the secound point of the first line ");
	scanf("%d%d",&m.q.x,&m.q.y);
	printf("enter first point of secound line ");
	scanf("%d%d",&n.p.x,&n.p.y);
	printf("enter the secound point of the secound line ");
	scanf("%d%d",&n.q.x,&n.q.y);
	g1=(float)(m.p.x-m.q.x)/(m.p.y-m.q.y);
	g2=(float)(n.p.x-n.q.x)/(n.p.y-n.q.y);
	if(g1==g2)
		printf("parral");
	else if(g1*g2==-1)
		printf("perpenticular");
	else
		printf("intersect");
	return 1;
}
