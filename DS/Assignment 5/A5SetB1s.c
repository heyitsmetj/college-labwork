#include <stdio.h>
#include <string.h>
#define MAX 100

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
    return (s->top == MAX - 1);
}

int isempty(stack *s)
{
    return (s->top == -1);
}

void push(stack *s, char c)
{
    if (!isfull(s))
        s->stk[++s->top] = c;
}

char pop(stack *s)
{
    if (!isempty(s))
        return s->stk[s->top--];
    return '\0';
}

void reverseString(char *str)
{
    stack s;
    initstack(&s);
    
    for (int i = 0; str[i]; i++)
        push(&s, str[i]);
    
    for (int i = 0; str[i]; i++)
        str[i] = pop(&s);
}

int main()
{
    char str[MAX];
    
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    
    printf("Original string: %s\n", str);
    
    reverseString(str);
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}