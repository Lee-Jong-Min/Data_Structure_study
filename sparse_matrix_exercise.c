#include <stdio.h>
#include <time.h>
#define MAX_TERMS 501
#define MAX_COL 501

typedef struct {
	int col;
	int row;
	int value;
} term;

void simple_transpose(term a[], term b[])
{
	int n, i, j, currentb;
	n = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = n;

	if (n > 0)
	{
		currentb = 1;
		for (i = 0; i < a[0].col; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (a[j].col == i)
				{
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
			}
		}
	}
}

void fast_trans(term a[], term b[])
{
	int row_terms[MAX_COL];
	int starting_pos[MAX_COL];
	int i, j;
	int num_cols = b[0].row = a[0].col;
	int num_terms = b[0].value = a[0].value;
	b[0].col = a[0].row;

	if (num_terms > 0)
	{
		for (i = 0; i < num_terms; i++)
			row_terms[i] = 0;
		for (i = 1; i <= num_terms; i++)
			row_terms[a[i].col]++;

		starting_pos[0] = 1;
		for (i = 1; i < num_cols; i++)
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

		for (i = 1; i <= num_terms; i++)
		{
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[j].value;
		}
	}
}

void main()
{
	FILE* fp, * ofp; // 파일 입출력을 위한 선언부 분 
	fp = fopen("TRANS알고리즘_original matrix.csv", "r");
	ofp = fopen("TRANS알고리즘_trans matrix.txt", "w");

	term a[MAX_TERMS], b[MAX_TERMS]; // 전치행렬을 만들기 위한 original matrix 선언부분 
	a[0].col = 500;
	a[0].row = 500;
	a[0].value = 500;

	clock_t start1, finish1, start2, finish2; // 알고리즘 실행시간 측정을 위한 선언부분 
	double duration_simple, duration_fast;

	int i; // 반복문 제어를 위한 선언부분 

	for (i = 1; i <= 500; i++)
	{
		fscanf(fp, "%d,%d,%d", &a[i].row, &a[i].col, &a[i].value);
	}
	for (i = 0; i < MAX_TERMS; i++) // original matrix a 출력구문 
	{
		printf("%d  %d  %d\n", a[i].row, a[i].col, a[i].value);
	}

	start1 = clock(); // simple_transpose 알고리즘 시간측정 

	for (i = 1; i <= 1000; i++)
	{
		simple_transpose(a, b);
	}

	finish1 = clock();
	duration_simple = (double)(finish1 - start1);

	start2 = clock(); // fast_trans 알고리즘 시간측정

	for (i = 1; i <= 1000; i++)
	{
		fast_trans(a, b);
	}

	finish2 = clock();
	duration_fast = (double)(finish2 - start2);

	for (i = 1; i <= 500; i++)
	{
		fprintf(ofp, "%d  %d  %d\n", b[i].row, b[i].col, b[i].value);
	}

	printf("\n");

	for (i = 0; i < MAX_TERMS; i++) // transpose matrix b 출력구문 
	{
		printf("%d  %d  %d\n", b[i].row, b[i].col, b[i].value);
	}

	printf("\n");

	printf("SIMPLE_TRANS 알고리즘의 클럭수는 %.0f입니다.\n\n", duration_simple);
	printf("FAST_TRANS 알고리즘의 클럭수는 %.0f입니다.\n", duration_fast);

	fclose(fp);
	fclose(ofp);
}