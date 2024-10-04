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

void preorder(NODE *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE *root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->data);
    }
}

void main()
{
    printf("\n Creating Binary Search Tree:\n");
    root=create();

    printf("\n Preorder traversal of the binary search tree is: ");
    preorder(root);

    printf("\n Postorder traversal of the binary search tree is: ");
    postorder(root);
}