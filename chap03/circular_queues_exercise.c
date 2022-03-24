#define _CRT_SECURE_NO_WARNINGS
#define MAX_QUEUE_SIZE 21
#include <stdio.h>
#include <string.h>

typedef struct {
	int key;
	char string[15];
} element;

void addq(int front, int* prear, element item);
element deleteq(int* pfront, int rear);
void queue_full(int* prear);
element queue_empty(int* pfront, int rear);

element queue[MAX_QUEUE_SIZE];
int rear = 0;
int front = 0;



int main()
{
	FILE* fp;
	fp = fopen("circular_queues_test.txt", "r");

	element data[5];
	element delete_queue;

	int i;

	for (i = 0; i < 5; i++)
	{
		fscanf(fp, "%d", &data[i].key);
		fgets(data[i].string, sizeof(data[i].string), fp);
		if (i < 4)
			data[i].string[strlen(data[i].string) - 1] = '\0';
		else
			data[i].string[strlen(data[i].string)] = '\0';
	}
	fclose(fp);
	
	for (i = 0; i < 5; i++)
	{
		addq(front, &rear, data[i]);
	}

	printf("queue에 들어있는 key와 string\n\n");
	printf("key      string\n");
	
	for (i = 1; i < 6; i++)
	{
		printf("%d      %s\n", queue[i].key, queue[i].string);
	}
	
	printf("\n");
	printf("queue에서 꺼낸 2개의 data의 key와 string\n\n");
	printf("key     string\n");
	
	for (i = 0; i < 2; i++)
	{
		delete_queue = deleteq(&front, rear);
		printf("%d      %s\n", delete_queue.key, delete_queue.string);
	}
	printf("\n");
	printf("front : %d   rear : %d\n", front, rear);
	return 0;
}

void addq(int front, int* prear, element item)
{
	*prear = (*prear + 1) % MAX_QUEUE_SIZE;
	if (front == *prear)
	{
		queue_full(prear);
		return;
	}
	queue[*prear] = item;
}

element deleteq(int* pfront, int rear)
{
	if (*pfront == rear)
		return queue_empty(pfront, rear);
	*pfront = (*pfront + 1) % MAX_QUEUE_SIZE;
	return queue[*pfront];
}

element queue_empty(int* pfront, int rear)
{
	if (*pfront == rear)
	{
		printf("%s\n", "Queue is empty");
		return queue[*pfront];
	}
}


void queue_full(int* prear)
{
	*prear = *prear - 1;
	printf("%s\n", "Queue is full");
}
