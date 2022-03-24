#include <stdio.h>
#define MAX_STACK_SIZE 3

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

void push(int* ptop, element item);
element pop(int* ptop);
void stack_full();
element stack_empty();

int main()
{
	int temp;

	pop(&top);
	push(&top, 1);
	push(&top, 2);

	temp = pop(&top);
	printf("%d\n", temp);

	push(&top, 3);
	push(&top, 4);
	push(&top, 5);

	temp = pop(&top);
	printf("%d\n", temp);

	return 0;
}

void push(int* ptop, element item)
{
	if (*ptop >= MAX_STACK_SIZE - 1)
	{
		stack_full();
		return;
	}
	stack[++ * ptop] = item;
}

element pop(int* ptop)
{
	if (*ptop == -1)
		return stack_empty();
	return stack[(*ptop)--];
}

void stack_full()
{
	printf("Full\n");
}

element stack_empty()
{
	printf("empty\n");
	return 1;
}