#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE
{
    char data;
    struct NODE *next;
};
typedef struct NODE node;

node *top = NULL;

node *getnode(char c)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = c;
    temp->next = NULL;
    return temp;
}

int isempty()
{
    return (top == NULL);
}

void push(char c)
{
    node *temp = getnode(c);
    if (top == NULL)
        top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }
}

char pop()
{
    if (isempty())
        return '\0';
    
    node *ptr = top;
    char c = ptr->data;
    top = top->next;
    free(ptr);
    return c;
}

void reverseString(char *str)
{
    for (int i = 0; str[i]; i++)
        push(str[i]);
    
    for (int i = 0; str[i]; i++)
        str[i] = pop();
}

int main()
{
    char str[100];
    
    printf("Enter a string: ");
    gets(str);
    
    printf("Original string: %s\n", str);
    
    reverseString(str);
    
    printf("Reversed string: %s\n", str);
    
    while (!isempty())
        pop();
    
    return 0;
}