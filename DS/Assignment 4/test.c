#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

typedef struct NODE node;
node *last, *list = NULL, *list2 = NULL;

node *getnode() // creates a node
{
	node *temp;

	temp = (node *)malloc(sizeof(node));

	printf("\n Enter the data for new node: ");
	scanf("%d", &temp->data);

	temp->next = NULL;

	return temp;
}

void create()
{
	node *temp;
	char ch;
	
	do{
		temp = getnode();
		
		if(list == NULL)
		{
			list = temp;
		}	
		else
		{
			last->next = temp;	
		}
		
		last = temp;
		
		printf("\n Do you want to create more nodes?(Y/N): ");
		scanf(" %c",&ch);
		
	}while(ch == 'Y' || ch =='y');
}

void display()
{
	node *ptr;
	
	printf("\n Linked List: ");
	for(ptr = list; ptr != NULL; ptr = ptr->next)
	{
		printf("%d->",ptr->data);
	}
	printf("NULL\n");
}

void insertbypos()
{
	int pos,i;
	node *ptr,*prev,*temp;
	
	temp = getnode();
	
	printf("\n Enter the position to insert the node ");
	
	for(ptr = list,prev = list,i=0; ptr != NULL && i < pos-1;prev = ptr,ptr = ptr->next);
	
	if(ptr != NULL && i < pos-1)
	{
		
	}
	
}

void main()
{
	int ch;
	
	while(1)
	{
		printf("\n\n --MENU--");
		printf("\n\n 1.Create the linked list.");
		printf("\n 2.Display the linked list.");
		printf("\n 3.Insert by Position.")
		printf("\n 4.Exit the program.");
		
		printf("\n\n Enter choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				create();
				break;
			
			case 2:
				display();
				break;
				
			case 3:
				insertbypos();
				break;
				
			case 4:
				printf("\n Exiting the program....\n");
				exit(1);
				
			default:
				printf("\n Invalid Choice! Try Again!");
				break;
		}
	}
	
}
