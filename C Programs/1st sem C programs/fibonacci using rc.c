#include<stdio.h>
void call_fibo(int x)
{
	static int i;
	if(i>=x)
		return;
	i=i+1;
	printf("%d ",fibo(i));
	call_fibo(x);
}
int fibo(int n)
{
	if(n==0||n==1)
		return n;
	else
		return(fibo(n-1)+fibo(n-2));
}
int main()
{
	int x;
	printf("how many fibonacci term you want: ");
	scanf("%d",&x);
	call_fibo(x);
	return 1;
}
