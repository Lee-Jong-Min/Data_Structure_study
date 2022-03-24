#include <stdio.h>

typedef struct {
	char data;
	struct list* link;
} list;





void printList(list* ptr)
{
	printf("Address Contents \n");

	for (; ptr; ptr = ptr->link)
	{
		printf("%8u %c\n", ptr, ptr->data);
	}
}

void main()
{
	list item1, item2, item3;

	item1.data = 'a';
	item2.data = 'b';
	item3.data = 'c';

	item1.link = item2.link = item3.link = NULL;
	item1.link = &item2;
	item2.link = &item3;

	list* listPtr = &item1;
	printList(listPtr);
}