//Dynamic Circluar QUEUE
#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

typedef struct NODE node;
node *front = NULL, *rear = NULL;

node *getnode(int data) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int isempty() {
    return (front == NULL);
}

void add(int data) {
    node *temp = getnode(data);
    if (isempty()) {
        front = temp;
        rear = temp;
        rear->next = front;  // Circular link
    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front;  // Maintain circular nature
    }
    printf("\nInserted %d\n", data);
}

int deleteq() {
    if (isempty()) {
        printf("\nQueue is empty. Deletion not possible.\n");
        return -1;
    }

    int data = front->data;
    node *temp = front;

    if (front == rear) {  // Only one element
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
        rear->next = front;  // Maintain circular nature
    }

    free(temp);
    return data;
}

void display() {
    if (isempty()) {
        printf("\nQueue is empty.\n");
        return;
    }

    node *ptr = front;
    printf("\nQueue contents: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != front);
    printf("\n");
}

int main() {
    int ch, data;
    printf("\nDynamic Circular Queue Initialized!\n");

    while (1) {
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Check if Empty\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the number to be inserted: ");
                scanf("%d", &data);
                add(data);
                break;
            case 2:
                data = deleteq();
                if (data != -1)
                    printf("\nDeleted element is: %d\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                if (isempty())
                    printf("\nQueue is empty.\n");
                else
                    printf("\nQueue is not empty.\n");
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
