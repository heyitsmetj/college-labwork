// NOT IN SLIP
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct STACK
{
    char stk[MAX];
    int top;
};
typedef struct STACK stack;

void initstack(stack *s)
{
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

void push(stack *s, char val)
{
    s->top++;
    s->stk[s->top] = val;
}

char pop(stack *s)
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
        printf(" %c", s->stk[i]);
}

char gettop(stack *s)
{
    return (s->stk[s->top]);
}

int isoperator(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
        return 1;
    else
        return 0;
}

int priority(char oper)
{
    if (oper == '^')
        return 4;
    else if (oper == '*' || oper == '/')
        return 3;
    else if (oper == '+' || oper == '-')
        return 2;
    else
        return 1;
}

int checktop(char topsymb)
{
    if (topsymb == '(' || topsymb == '{' || topsymb == '[')
        return 1;
    else
        return 0;
}

void inpostfix(char *E)
{
    int i, j = 0;
    char symbol, postfix[MAX], topsymb;
    stack s;
    initstack(&s);

    for (i = 0; E[i] != '\0'; i++)
    {
        symbol = E[i];

        if (symbol == '(' || symbol == '{' || symbol == '[')
            push(&s, symbol);

        else if (isoperator(symbol) == 1)
        {
            while (priority(gettop(&s)) >= priority(symbol))
                postfix[j++] = pop(&s);

            push(&s, symbol);
        }

        else if (symbol == ')' || symbol == '}' || symbol == ']')
        {
            topsymb = pop(&s);

            while (!checktop(topsymb))
            {
                postfix[j++] = topsymb;
                topsymb = pop(&s);
            }
        }
        else
            postfix[j++] = symbol;
            postfix[j] = '\0';
            display(&s);
    }

    while (!isempty(&s))
    {
        postfix[j++] = pop(&s);
        postfix[j] = '\0';
    }

    postfix[j] = '\0';
    printf("\nPostfix expression: %s", postfix);
}

int main()
{
    char expr[MAX];

    printf("Enter infix expression: ");
    scanf("%s", expr);

    printf("\nInfix expression: %s", expr);

    inpostfix(expr);

    return 0;
}