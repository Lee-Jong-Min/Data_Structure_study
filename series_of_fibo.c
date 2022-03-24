#include <stdio.h>
#include <time.h>


int fibo(n)
{
	if(n == 0)
		return 0;	
	if(n == 1)
		return 1;
	else
		return fibo(n-1) + fibo(n-2);
}

void main()
{
	int i,n;	
	printf("n을 입력하시오 : ");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		printf("%d  ",fibo(i));
}