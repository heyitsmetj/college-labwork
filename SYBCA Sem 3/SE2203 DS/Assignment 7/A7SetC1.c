#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
};

typedef struct NODE node;

node *getnodenum(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return getnodenum(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

node *search(node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void mirror(node *root)
{
    if (root == NULL)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int findLargest(node *root)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return -1; // Indicate that the tree is empty
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int findSmallest(node *root)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return -1; // Indicate that the tree is empty
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n1. Insert an element\n");
        printf("2. Search for an element\n");
        printf("3. Create mirror of the tree\n");
        printf("4. Find largest value\n");
        printf("5. Find smallest value\n");
        printf("6. Display In-Order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            node *result = search(root, value);
            if (result != NULL)
            {
                printf("Value %d found in the tree.\n", value);
            }
            else
            {
                printf("Value %d not found in the tree.\n", value);
            }
            break;

        case 3:
            mirror(root);
            printf("The tree has been mirrored.\n");
            break;

        case 4:
            value = findLargest(root);
            if (value != -1)
            {
                printf("Largest value in the tree is: %d\n", value);
            }
            break;

        case 5:
            value = findSmallest(root);
            if (value != -1)
            {
                printf("Smallest value in the tree is: %d\n", value);
            }
            break;

        case 6:
            printf("In-Order Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
