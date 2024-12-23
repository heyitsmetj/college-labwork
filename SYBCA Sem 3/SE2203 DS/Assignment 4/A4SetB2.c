#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	struct NODE *prev;
	int data;
	struct NODE *next;
};

typedef struct NODE node;
node *list = NULL,*last;

node * getnode()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));

	printf("\n Enter the data for new node: ");
	scanf("%d",&temp->data);

	temp->prev = NULL;
	temp->next = NULL;

	return temp;
}

node * create(node * list)
{
	char ch;
	node *temp,*last,*previous = NULL;

	do {
		temp = getnode();

		if(list == NULL)
		{
			list = temp;
		}
		else
		{
			for(last = list, previous = list; last->next != NULL; previous=last,last = last->next);
			last->prev = previous;
			last->next = temp;
		}

		printf("\n Do you want to enter more nodes?(Y/N): ");
		scanf(" %c",&ch);

	} while(ch == 'Y' || ch == 'y');

	return (list);

}

void display()
{
	node *ptr;

	printf("\n\n Doubly Linked List: NULL->");
	for(ptr = list; ptr != NULL; ptr = ptr->next)
	{
		printf("<-%d->",ptr->data);
	}
	printf("<-NULL\n");
}

void insertval()
{
    int val;
    node *temp,*ptr,*previous = NULL;
    
    printf("\n Creating a new node!\n\n");
    
    temp = getnode();
    
    display();
    printf("\n Enter the value of node after which new node is to be placed: ");
    scanf("%d",&val);
    
    for(ptr = list,previous = list; ptr != NULL && val != ptr->data;previous = ptr,ptr = ptr->next);
    
    
    if(ptr == list && previous == list)
    {
        temp->next = ptr->next;
        list = temp;
    }
    
    if(ptr !=NULL && val == ptr->data)
    {
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
    }
    else
    {
        printf("\n Value not Found!\n");
        return;
    }
    
    printf("\n New node inserted!\n");
    display();
}

void delete()
{
    int val;
    node *temp,*ptr,*previous = NULL,*forward=NULL;
    
    display();
    printf("\n Enter the value of node to be deleted: ");
    scanf("%d",&val);
    
    for(ptr = list,previous = list,forward = ptr->next; ptr != NULL && val != ptr->data;previous = ptr,ptr = ptr->next,forward = ptr->next);
    
    
    if(ptr == list && previous == list)
    {
        list = ptr->next;
        list->prev = NULL;
    }
    
    if(ptr !=NULL && val == ptr->data)
    {
        previous->next = ptr->next;
        forward->prev = previous;
    }
    else
    {
        printf("\n Value not Found!\n");
        return;
    }
    
    printf("\n Node Deleted!\n");
    free(ptr);
    display();
}

void main()
{
	int ch;

	while(1)
	{
		printf("\n --Menu--\n");
		printf("\n 1.Create Doubly Linked List.");
		printf("\n 2.Display the Doubly Linked List.");
		printf("\n 3.Insert new node by value.");
		printf("\n 4.Delete a node by value.");
		printf("\n 5.Exit.");

		printf("\n\n Enter Choice: ");
		scanf("%d",&ch);


		switch(ch)
		{
		case 1:
			list = create(list);
			break;

		case 2:
			display();
			break;
			
		case 3:
		    insertval();
		    break;
		    
		case 4:
		    delete();
		    break;

		case 5:
			printf("\n Exiting...");
			exit(1);

		default:
			printf("\n\n Try Again!");
			break;
		}
	}
}