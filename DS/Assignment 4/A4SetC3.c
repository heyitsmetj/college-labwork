#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

typedef struct NODE node;
node *list1 = NULL,*list2 = NULL,*ilist = NULL,*last;

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


void intersection(node *list1, node *list2)
{
	node *ptr1,*ptr2,*temp;

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

	for(ptr1=list1; ptr1 != NULL;ptr1 = ptr1->next)
	{
		for(ptr2=list2; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if(ptr1->data == ptr2->data)
            {
                if(ilist == NULL)
                {
					temp = (node *)malloc(sizeof(node));
					temp->data = ptr1->data;
					temp->next = NULL;
					ilist = temp;
                    
                }
                else
                {
                    temp = (node *)malloc(sizeof(node));
					temp->data = ptr1->data;
					temp->next = NULL;

					for(last = ilist;last->next != NULL;last = last->next);
					last->next = temp;
                }
            }
        }
	}

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
	
	intersection(list1,list2);

	printf("\n\n Intersection Linked list: ");
	display(ilist);
}