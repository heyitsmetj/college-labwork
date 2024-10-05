#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50

struct STACK
{
    double stk[MAX];
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

void push(stack *s, double val)
{
    if (isfull(s))
    {
        printf("Stack is FULL!\n");
        return;
    }
    s->top++;
    s->stk[s->top] = val;
}

double pop(stack *s)
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
    {
        printf(" %.2f", s->stk[i]);
    }
}

int isdigits(char symb)
{
    return (symb >= '0' && symb <= '9');
}

double oper(char symb, double opnd1, double opnd2)
{
    switch (symb)
    {
    case '+':
        return opnd1 + opnd2;
    case '-':
        return opnd1 - opnd2;
    case '*':
        return opnd1 * opnd2;
    case '/':
        return opnd1 / opnd2;
    case '^':
        return pow(opnd1, opnd2);
    default:
        printf("Invalid operator: %c\n", symb);
        return 0;
    }
}

double eval(char *E)
{
    double opnd1, opnd2, value;
    stack opndstk;
    initstack(&opndstk);

    for (int i = 0; E[i] != '\0'; i++)
    {
        if (isdigits(E[i]))
        {
            push(&opndstk, E[i] - '0');
        }
        else
        {
            opnd2 = pop(&opndstk);
            opnd1 = pop(&opndstk);
            value = oper(E[i], opnd1, opnd2);
            push(&opndstk, value);
        }
    }
    return pop(&opndstk);
}

int main()
{
    char expr[MAX];

    printf("\nEnter postfix expression: ");
    scanf("%s", expr);

    printf("\nResult: %.2f\n", eval(expr));

    return 0;
}
