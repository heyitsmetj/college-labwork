#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct STACK
{
    int top;
    int stk[MAX];
};
typedef struct STACK stack;

void initstack(stack *s)
{
    s->top = -1;
}

int isempty(stack *s)
 {
    if(s->top == -1)
    return 1;
    else
    return 0;
 }

 int isfull(stack *s)
 {
    if(s->top == MAX-1)
    return 1;
    else
    return 0;
 }
 
 void push(stack *s)
 {
    if(isfull(s))
        printf("\n Stack is FULL!");
    else
    {
        printf("\n Enter a number to push: ");
        scanf("%d",&s->stk[++s->top]);
        printf("\n %d pushed to stack.",s->stk[s->top]);
    }
 }
 
 int pop(stack *s)
 {
    if(isempty(s))
        printf("\n Stack is EMPTY!");
    else
        return s->stk[s->top--];
 }

 void display(stack *s)
 {
    if(isempty(s))
        printf("\n Stack is EMPTY!");
    else
    {
        printf("\n Stack elements are: ");
        for(int i=s->top;i>=0;i--)
            printf("\n %d",s->stk[i]);
    }
 }

 void main()
 {
    int ch;
    stack s;

    while (1)
    {
        printf("\n 1.Initialize Stack.");
        printf("\n 2.Push.");
        printf("\n 3.Pop.");
        printf("\n 4.Display.");
        printf("\n 5.Exit.");
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                initstack(&s);
                printf("\n Stack initialized.");
                break;
            case 2:
                push(&s);
                break;
            case 3:
                printf("\n %d popped from stack.",pop(&s));
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("\n Wrong choice.");
        }  
    }
    
 }
