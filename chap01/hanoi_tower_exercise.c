#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void hanoi_tower(int n, char from, char tmp, char to)
{
	if(n == 1)
		printf("원판 1을 %c에서 %c으로 옮긴다.\n",from,to);
	else
	{
		hanoi_tower(n-1,from,to,tmp);
		printf("원판 %d을 %c에서 %c으로 ケ芽.\n",n,from,to);
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
	printf("%lf 클럭입니다.",duration);

}
