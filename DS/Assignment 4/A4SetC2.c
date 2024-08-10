#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

typedef struct NODE node;
node *list1 = NULL,*list2 = NULL,*last;

node *getnode()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));

	printf("\n Enter the data for new node: ");
	scanf("%d", &temp->data);
	
	temp->next = NULL;

	return temp;
}

node *create(node *list)
{
	char ch;
	node *temp, *last;

	do
	{
		temp = getnode();

		if (list == NULL)
		{
			list = temp;
		}
		else
		{
			for (last = list; last->next != NULL; last = last->next)
			;
			last->next = temp;

		}

		printf("\n Do you want to enter more nodes?(Y/N): ");
		scanf(" %c", &ch);

	} while (ch == 'Y' || ch == 'y');

	return (list);
}

void display(node *list)
{
	node *ptr;

	for (ptr = list; ptr != NULL; ptr = ptr->next)
	{
		printf("%d->", ptr->data);
	}
	printf("NULL");
}


void concatenate(node *list1, node *list2)
{
	node *ptr;

    if (list1 == NULL)
    {
		printf("\n List1 is Empty!");
		create(list1);
	}
	if (list2 == NULL)
	{
		printf("\n List2 is Empty!");
        create(list2);
	}

	for(ptr=list1; ptr->next != NULL;ptr = ptr->next);
	ptr->next = list2;
}

void main()
{
	printf("\n Creating 1st List:\n");
	list1 = create(list1);
	printf("\n Creating 2nd List:\n");
	list2 = create(list2);
	
	printf("\n 1st Linked list: ");
	display(list1);
	printf("\n 2nd Linked List: ");
	display(list2);
	
	concatenate(list1,list2);

	printf("\n\n Linked list after concatenation: ");
	display(list1);
}