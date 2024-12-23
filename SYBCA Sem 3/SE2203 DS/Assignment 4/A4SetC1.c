#include <stdio.h>
#include <stdlib.h>
struct NODE
{
	int coef;
	int exp;
	struct NODE *next;
};
typedef struct NODE node;

node *getnodenum(int co, int ex)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->coef = co;
	temp->exp = ex;
	temp->next = NULL;
	return temp;
}

node *getnode()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	printf("\nEnter the coefficient: ");
	scanf("%d", &temp->coef);
	printf("\nEnter the exponent: ");
	scanf("%d", &temp->exp);
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

		printf("\nDo you want to enter any more nodes(Y/N): ");
		scanf(" %c", &ch);

	} while (ch == 'Y' || ch == 'y');

	return list;
}

void display(node *list)
{
	node *ptr;
	if (list == NULL)
		printf("NULL list");
	else
	{
		for (ptr = list; ptr->next != NULL; ptr = ptr->next)
		{
			printf("%dx^%d + ", ptr->coef, ptr->exp);
		}
		if (ptr->exp == 0)
		{
			printf("%d", ptr->coef);
		}
		else
		{
			printf("%dx^%d", ptr->coef, ptr->exp);
		}
	}
}

node *addpoly(node *list1, node *list2)
{
	node *aptr, *bptr, *list3 = NULL, *temp, *last, *ptr;

	int co;
	for (aptr = list1, bptr = list2; aptr != NULL, bptr != NULL;)
	{
		if (aptr->exp == bptr->exp)
		{
			co = aptr->coef + bptr->coef;
			temp = getnodenum(co, aptr->exp);
			aptr = aptr->next;
			bptr = bptr->next;
		}

		else if (aptr->exp > bptr->exp)
		{
			temp = getnodenum(aptr->coef, aptr->exp);
			aptr = aptr->next;
		}
		else if (aptr->exp < bptr->exp)
		{
			temp = getnodenum(bptr->coef, bptr->exp);
			bptr = bptr->next;
		}

		if (list3 == NULL)
		{
			list3 = temp;
		}
		else
		{
			for (last = list3; last->next != NULL; last = last->next)
				;
			last->next = temp;
		}
	}

	while (aptr != NULL)
	{
		temp = getnodenum(aptr->coef, aptr->exp);
		for (last = list3; last->next != NULL; last = last->next)
			;
		last->next = temp;
		aptr = aptr->next;
	}

	while (bptr != NULL)
	{
		temp = getnodenum(bptr->coef, bptr->exp);
		for (last = list3; last->next != NULL; last = last->next)
			;
		last->next = temp;
		bptr = bptr->next;
	}

	return list3;
}

void main()
{
	node *list1 = NULL, *list2 = NULL, *list3 = NULL;
	
	printf("\nCreate list of poly1: ");
	list1 = create(list1);
	
	printf("\nEntered poly1: ");
	display(list1);

	printf("\n");

	printf("\nCreate list of poly2: ");
	list2 = create(list2);
	
	printf("\nEntered poly2: ");
	display(list2);

	printf("\n");

	list3 = addpoly(list1, list2);
	
	printf("\nAddition of poly1 and poly2: ");
	display(list3);

	printf("\n");
}