#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>




void main()
{
	int i,n,j;

	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
			printf("%c",'*');
		printf("\n");
	}
}