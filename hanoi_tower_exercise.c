#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void hanoi_tower(int n, char from, char tmp, char to)
{
	if(n == 1)
		printf("���� 1�� %c���� %c���� �ű��.\n",from,to);
	else
	{
		hanoi_tower(n-1,from,to,tmp);
		printf("���� %d�� %c���� %c���� �����.\n",n,from,to);
		hanoi_tower(n-1,tmp,from,to);
	}
}

void main()
{
	clock_t start,finish;
	double duration;

	start = clock();
	hanoi_tower(15,'A','B','C');
	finish = clock();
	duration = (double)(finish - start);
	printf("%lf Ŭ���Դϴ�.",duration);

}