//Static Linear QUEUE
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct QUEUE {
    int data[MAX];
    int front;
    int rear;
};
typedef struct QUEUE queue;

void initqueue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isempty(queue *q) {
    return (q->front == -1);
}

int isfull(queue *q) {
    return (q->rear == MAX - 1);
}

void add(queue *q, int data) {
    if (isfull(q)) {
        printf("\nQueue is full. Insertion not possible.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = data;
        printf("\nInserted %d\n", data);
    }
}

int deleteq(queue *q) {
    int data;
    if (isempty(q)) {
        printf("\nQueue is empty. Deletion not possible.\n");
        return -1;
    } else {
        data = q->data[q->front];
        if (q->front == q->rear) {  // Only one element
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        return data;
    }
}

void display(queue *q) {
    if (isempty(q)) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue contents: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

int main() {
    queue q;
    int ch, data;

    initqueue(&q);
    printf("\nStatic Linear Queue Initialized!\n");

    while (1) {
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Check if Empty\n5. Check if Full\n6. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the number to be inserted: ");
                scanf("%d", &data);
                add(&q, data);
                break;
            case 2:
                data = deleteq(&q);
                if (data != -1)
                    printf("\nDeleted element is: %d\n", data);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                if (isempty(&q))
                    printf("\nQueue is empty.\n");
                else
                    printf("\nQueue is not empty.\n");
                break;
            case 5:
                if (isfull(&q))
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
