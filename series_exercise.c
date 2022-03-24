#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>




void main()
{
	int i,n,sum;
	sum = 0;
	scanf("%d",&n);
	for (i=0;i<=n;i++)
		sum = sum + i;

	printf("1부터 %d까지 합 : %d",n,sum);
}