//NOT IN SLIP
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct STACK
{
    int stk[MAX];
    int top;
};
typedef struct STACK stack;

void initstack(stack *s)
{
    for (int i = 0; i < MAX; i++)
        s->stk[i] = 0;
    s->top = -1;
}

int isfull(stack *s)
{
    return (s->top == MAX - 1);
}

int isempty(stack *s)
{
    return (s->top == -1);
}

void push(stack *s, int val)
{
    if (isfull(s))
    {
        printf("\nStack is FULL!");
        return;
    }
    s->stk[++s->top] = val;
}

int pop(stack *s)
{
    if (isempty(s))
    {
        printf("\nStack is EMPTY!");
        return -1;
    }
    return s->stk[s->top--];
}

void display(stack *s)
{
    printf("\nStack Elements: ");
    for (int i = s->top; i > -1; i--)
        printf("%d ", s->stk[i]);
}

void peek(stack *s)
{
    if (isempty(s))
    {
        printf("\nStack is EMPTY!");
        return;
    }
    printf("\nTop element is: %d.", s->stk[s->top]);
}

void insertAtBottom(stack *s, int item)
{
    if (isempty(s))
    {
        push(s, item);
    }
    else
    {
        int temp = pop(s);
        insertAtBottom(s, item);
        push(s, temp);
    }
}

void reverseStack(stack *s)
{
    if (!isempty(s))
    {
        int item = pop(s);
        reverseStack(s);
        insertAtBottom(s, item);
    }
}

int main()
{
    stack s;
    int ch, val;
    initstack(&s);

    while (1)
    {
        printf("\n\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Reverse Stack\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (isfull(&s))
                printf("\nStack is FULL!");
            else
            {
                printf("\nEnter value to PUSH: ");
                scanf("%d", &val);
                push(&s, val);
                printf("%d PUSHED into STACK.", val);
            }
            break;
        case 2:
            if (isempty(&s))
                printf("\nStack is EMPTY!");
            else
            {
                val = pop(&s);
                printf("\nPopped value: %d", val);
            }
            break;
        case 3:
            if (isempty(&s))
                printf("\nStack is EMPTY!");
            else
                display(&s);
            break;
        case 4:
            peek(&s);
            break;
        case 5:
            if (isempty(&s))
                printf("\nStack is EMPTY!");
            else
            {
                reverseStack(&s);
                printf("\nStack reversed successfully.");
            }
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }
    return 0;
}