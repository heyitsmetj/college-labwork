#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int coeff;
	int expo;
	struct NODE *next;
};

typedef struct NODE node;
node *list = NULL, *last;

node *getnode()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));

	printf("\n Enter the coefficient for new node: ");
	scanf("%d", &temp->coeff);
	printf("\n Enter the exponent for new node: ");
	scanf("%d", &temp->expo);

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

		printf("\n Do you want to extend the expression?(Y/N): ");
		scanf(" %c", &ch);

	} while (ch == 'Y' || ch == 'y');

	return (list);
}

void display(node *list)
{
	node *ptr;

	for (ptr = list; ptr != NULL; ptr = ptr->next)
	{
		printf(" %d^%d ", ptr->coeff, ptr->expo);

		if (ptr->next != NULL)
		{
			printf("+");
		}
	}
}

node * additionofpolynomial(node *list)
{
	node *ptr1, *ptr2, *result = NULL, *temp;
	int sum;

	ptr1 = list;

	while (ptr1 != NULL)
	{
		ptr2 = list;

		while (ptr2 != NULL)
		{
			if (ptr1->expo == ptr2->expo)
			{
				sum = ptr1->coeff + ptr2->coeff;

				if (sum != 0)
				{
					temp = (node *)malloc(sizeof(node));
					temp->coeff = sum;
					temp->expo = ptr1->expo;
					temp->next = NULL;

					if (result == NULL)
					{
						result = temp;
					}
					else
					{
						last->next = temp;
					}

					last = temp;
				}

				ptr2 = ptr2->next;
			}
		}
	}
	return result;
}

void main()
{
	printf("\n Creating Polynomial:\n");
	list = create(list);

	printf("\n\n Your Polynomial: ");
	display(list);
	printf("\n\nPolynomial after addition: ");
	node * result = additionofpolynomial(list);
	display(result);
}