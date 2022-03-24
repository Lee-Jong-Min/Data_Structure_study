#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>




void main()
{
	int i,n,sum;
	sum = 0;
	scanf("%d",&n);
	for (i=0;i<=n;i++)
		sum = sum + i;

	printf("1ºÎÅÍ %d±îÁö ÇÕ : %d",n,sum);
}
