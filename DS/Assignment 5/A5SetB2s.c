#include <stdio.h>
#include <string.h>
#define MAX 100

struct STACK
{
    int stk[MAX];
    int top;
};
typedef struct STACK stack;

void initstack(stack *s)
{
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

void push(stack *s, int n)
{
    if (!isfull(s))
        s->stk[++s->top] = n;
}

char pop(stack *s)
{
    if (!isempty(s))
        return s->stk[s->top--];
    else
        return 0;
}

int reversenum(int num,stack *s)
{
    int rev = 0;
    int temp = num;
    while (temp != 0)
    {
        int rem = temp % 10;
        push(&s,rem);
        temp = temp / 10;
    }
}

int main()
{
    int num;
    stack s;
    initstack(&s);

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Original num: %d\n", num);

    reversenum(num,&s);

    printf("Reversed num: ");
    while (!isempty(&s))
    {
        printf("%d", pop(&s));
    }

    return 0;
}