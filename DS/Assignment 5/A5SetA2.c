//Dynamic Stack Implementation

#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE node;
node *top = NULL;

node *getnode()
{
    node *temp;

    temp = (node *)malloc(sizeof(node));

    printf("\n Enter the data: ");
    scanf("%d", &temp->data);

    temp->next = NULL;

    return temp;
}

int isempty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

void push()
{
    node *temp;
    char ch;

    do
    {
        temp = getnode();

        if (top == NULL)
            top = temp;

        else
        {
            temp->next = top;
            top = temp;
        }

        printf("\n Element %d PUSHED successfully!",temp->data);

        printf("\n Do you want to enter more nodes?(Y/N): ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');
}

void pop()
{
    node *ptr;
    ptr = top;

    if (isempty())
        printf("\n Stack is EMPTY!");

    else
    {
        printf("\n Node with element %d POPPED successfully!", ptr->data);
        top = top->next;
        free(ptr);
    }
}

void display()
{
    node *ptr;
    ptr = top;

    if (isempty())
        printf("\n Stack is EMPTY!");
    else
    {
        printf("\n Stack elements are: ");
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
    }
}

void main()
{
    int ch;

    while (1)
    {
        printf("\n\n----MENU----\n");
        printf("\n 1. PUSH an element in Stack.");
        printf("\n 2. POP an element from Stack.");
        printf("\n 3. Display the Stack.");
        printf("\n 4. Exit.");

        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
           case 1:
                push();
                break;

            case 2:
                pop();
                break;
        
            case 3:
                display();
                break;
        
            case 4:
                printf("\n Exiting the program...\n");
                exit(1);

            default:
                printf("\n Invalid Choice, Try Again!");
        }
    }
}
