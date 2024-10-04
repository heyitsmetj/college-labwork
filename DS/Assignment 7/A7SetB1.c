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

NODE * insert(NODE *root)
{
    NODE *temp,*ptr;
    temp=getnode();
    if(root==NULL)
    {
        root=temp;
        return root;
    }
    else
    {
        ptr=root;
        while(1)
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
        return root;
    }
}

int countNonLeafNodes(NODE* root) {
    if (root == NULL || (root->lchild == NULL && root->rchild == NULL)) {
        return 0;
    }
    return 1 + countNonLeafNodes(root->lchild) + countNonLeafNodes(root->rchild);
}

int countLeafNodes(NODE* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->lchild == NULL && root->rchild == NULL) {
        return 1;
    }
    return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);
}

int countTotalNodes(NODE* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countTotalNodes(root->lchild) + countTotalNodes(root->rchild);
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
    int ch;
    while(1)
    {
        printf("\n\nBinary Search Tree Operations:\n");
        printf("\n1. Insert a new node.");
        printf("\n2. Count non-leaf nodes.");
        printf("\n3. Count leaf nodes.");
        printf("\n4. Count total nodes.");
        printf("\n5. Inorder traversal.");
        printf("\n6. Exit.");
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                root=insert(root);
                break;
                
            case 2:
            {
                int nonLeafNodes = countNonLeafNodes(root);
                printf("\nNumber of non-leaf nodes: %d\n", nonLeafNodes);
                break;
            }
            
            case 3:
            {
                int leafNodes = countLeafNodes(root);
                printf("\nNumber of leaf nodes: %d\n", leafNodes);
                break;
            }
            
            case 4:
            {
                int totalNodes = countTotalNodes(root);
                printf("\nTotal number of nodes: %d\n", totalNodes);
                break;
            }
            
            case 5:
            {
                printf("\nInorder traversal of the binary search tree is: ");
                inorder(root);
                printf("\n");
                break;
            }
            
            case 6:
            {
                printf("\nExiting...\n");
                exit(0);
            }
            
            default:
            {
                printf("\nInvalid choice! Please try again.\n");
            }

        }
    }
}