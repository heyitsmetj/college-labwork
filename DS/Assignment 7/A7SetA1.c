#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild,*rchild;
};

typedef struct node NODE;
NODE *root = NULL;

NODE * getnode()
{
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    printf("\n Enter data: ");
    scanf("%d",&temp->data);
    temp->lchild=temp->rchild=NULL;
    return temp;
}

NODE * create()
{
    NODE *temp,*ptr;
    char ch;

    do{
        temp=getnode();
        if(root==NULL)
            root=temp;
        
        else
        {
            ptr=root;

            while(ptr != NULL)
            {
                if(temp->data<ptr->data)
                {
                    if(ptr->lchild==NULL)
                    {
                        ptr->lchild=temp;
                        break;
                    }
                    ptr=ptr->lchild;
                }
                else
                {
                    if(ptr->rchild==NULL)
                    {
                        ptr->rchild=temp;
                        break;
                    }
                    ptr=ptr->rchild;
                }
            }
        }

        printf("\n Add more node? (Y/N): ");
        scanf(" %c",&ch);    
    }while(ch == 'Y' || ch == 'y');

    return (root);
}

void inorder(NODE *root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}

void main()
{
    printf("\n Creating Binary Search Tree:\n");
    root=create();
    printf("\n Inorder traversal of the binary search tree is: ");
    inorder(root);
}