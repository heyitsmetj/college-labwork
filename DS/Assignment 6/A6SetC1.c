//Static Circular QUEUE
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front, rear;

void initqueue() {
    front = -1;
    rear = -1;
}

int isempty() {
    return (front == -1);
}

int isfull() {
    return ((rear + 1) % MAX == front);
}

void add(int data) {
    if (isfull()) {
        printf("\nQueue is full. Insertion not possible.\n");
        return;
    }
    if (isempty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = data;
    printf("\nInserted %d\n", data);
}

int deleteq() {
    int data;

    if (isempty()) {
        printf("\nQueue is empty. Deletion not possible.\n");
        return -1;
    }

    data = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return data;
}

void display() {
    if (isempty()) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue contents: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int ch, data;
    initqueue();
    printf("\nStatic Circular Queue Initialized!\n");

    while (1) {
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Check if Empty\n5. Check if Full\n6. Exit\nEnter your choice: ");
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
                if (isfull())
                    printf("\nQueue is full.\n");
                else
                    printf("\nQueue is not full.\n");
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
