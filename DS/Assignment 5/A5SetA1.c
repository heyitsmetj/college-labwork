#include <stdio.h>
#include <stdlib.h>

// Implementing Static Stack of integers using array

#define MAX 5

int stack[MAX];
int top = -1;

// Function to check if stack is full
int isFull()
{
    return top == MAX - 1;
}

// Function to initialize stack

void initializeStack()
{
    top = -1;
}

// Function to check if stack is empty
int isEmpty()
{
    return top == -1;
}

// Function to push an element onto the stack
void push(int value)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

// Function to peek the top element of the stack
int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack[top];
}

// Function to display the elements of the stack
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}


int main()
{
    push(10);
    push(20);
    push(30);

    printf("Top element is: %d\n", peek());

    pop();
    display();

    return 0;
}
