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
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(stack *s)
{
    int val;
    printf("\n Enter value to PUSH: ");
    scanf("%d", &val);

    s->stk[++s->top] = val;

    printf(" %d PUSHED into STACK.", val);
}

void pop(stack *s)
{
    int val;
    val = s->stk[s->top--];
    printf("\n Popped value: %d", val);
}

void display(stack *s)
{
    printf("\n Stack Elements: ");
    for (int i = s->top; i > -1; i--)
        printf("%d ", s->stk[i]);
}

void peek(stack *s)
{
    printf("\n Top element is: %d.", s->stk[s->top]);
}

void main()
{
    stack s;
    int ch;

    initstack(&s);

    while (1)
    {
        printf("\n\n Stack Operations\n");
        printf(" 1. Push\n");
        printf(" 2. Pop\n");
        printf(" 3. Display\n");
        printf(" 4. Peek\n");
        printf(" 5. Exit\n");
        
        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (isfull(&s))
                printf("\n Stack is FULL!");
            else
                push(&s);
            break;

        case 2:
            if (isempty(&s))
                printf("\n Stack is EMPTY!");
            else
                pop(&s);
            break;

        case 3:
            if (isempty(&s))
                printf("\n Stack is EMPTY!");
            else
                display(&s);
            break;
        case 4:
            if (isempty(&s))
                printf("\n Stack is EMPTY!");
            else
                peek(&s);

        case 5:
            exit(0);

        default:
            printf("\n Invalid choice!\n");
            break;
        }
    }
}