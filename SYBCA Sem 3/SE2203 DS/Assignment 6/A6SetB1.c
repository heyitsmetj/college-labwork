//Dynamic Linear QUEUE
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE node;
node *front,*rear;

node *getnodenum(int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void add(int data)
{
    node *temp;
    temp = getnodenum(data);
    if (front == NULL)
    {
        rear = temp;
        front = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int deleteq()
{
    int val;
    node *ptr;
    val = front->data;
    ptr = front;

    if (front->next != NULL)
        front = front->next;

    else
    {
        front = NULL;
        rear = NULL;
    }

    free(ptr);
    return val;
}

void display()
{
    node *ptr;
    printf("\n Queue contents: ");
    for (ptr = front; ptr != rear; ptr = ptr->next)
        printf("%d ", ptr->data);
    printf("%d ", ptr->data);
}

void initqueue()
{
    front = NULL;
    rear = NULL;
}

int isempty()
{
    return (front == NULL);
}

void main()
{
    int ch, data;
    initqueue();
    printf("\n Dynamic Queue Initialized!\n");

    while (1)
    {
        printf("\n 1. Insertion\n 2. Deletion\n 3. Display\n 4. Isempty.\n 5. Isempty.\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\n Enter the number to be inserted: ");
                scanf("%d", &data);
                add(data);
                break;
            case 2:
                data = deleteq();
                printf("\n Deleted element is: %d\n", data);
                break;
            case 3:
                display();
                break;
                case 4:
                if (isempty())
                    printf("\n Queue is empty.\n");
                    else
                    printf("\n Queue is not empty.\n");
                    break;
            case 5:
                exit(0);
            default:
                printf("\n Invalid choice!\n");
        }
    }
}