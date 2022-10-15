#include<stdio.h>
#include<math.h>
float check_distence(int x1,int x2,int y1,int y2)
{
	float t;
	t=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	return t;
}
float find_area(int x1,int y1,int x2,int y2,int x3,int y3)
{
	float a,b,c,s,area;
	a=check_distence(x1,x2,y1,y2);
	b=check_distence(x1,x3,y1,y3);
	c=check_distence(x2,x3,y2,y3);
	s=(a+b+c)/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	return area;
}
int main()
{
	int x1,x2,x3,y1,y2,y3;
	float area;
    printf("Enter the value of first point (x1,y1) : ");
	scanf("%d%d",&x1,&y1);
	printf("Enter the value of second point (x2,y2) : ");
	scanf("%d%d",&x2,&y2);     	
	printf("Enter the value of third point (x3,y3) : ");
	scanf("%d%d",&x3,&y3);
	area=find_area(x1,y1,x2,y2,x3,y3);
	printf("Area of the triangle is :%f\n",area);
	return 1;
}

