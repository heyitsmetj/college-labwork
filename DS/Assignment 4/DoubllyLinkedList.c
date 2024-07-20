#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct NODE {
    int data;
    struct NODE *next;
    struct NODE *prev;
};

typedef struct NODE node;
node *last, *list = NULL;

// Function to create a new node
node *getnode() {
    node *temp = (node *)malloc(sizeof(node));
    printf("\n Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Function to create the doubly linked list
void create() {
    node *temp;
    char ch;
    do {
        temp = getnode();
        if (list == NULL) {
            list = temp;
        } else {
            last->next = temp;
            temp->prev = last;
        }
        last = temp;

        printf("\n Do you want to enter more nodes? (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
}

// Function to display the doubly linked list
void display() {
    node *ptr;
    printf("\n Doubly Linked List: ");
    for (ptr = list; ptr != NULL; ptr = ptr->next) {
        printf("\t %d", ptr->data);
    }
    printf("\n");
}

// Function to count the nodes in the doubly linked list
int countnode() {
    node *ptr;
    int cnt;
    for (ptr = list, cnt = 0; ptr != NULL; ptr = ptr->next, cnt++);
    return cnt;
}

// Function to delete a node from the doubly linked list
void deletenode() {
    int pos, i;
    node *curr, *prev = NULL;

    if (list == NULL) {
        printf("List is empty.\n");
        return;
    }

    display();
    printf("Enter position to delete (starting from 1): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    for (curr = list, i = 1; curr != NULL && i < pos; prev = curr, curr = curr->next, i++);

    if (curr == NULL) {
        printf("Position %d not found.\n", pos);
        return;
    }

    if (prev == NULL) {
        list = curr->next;
        if (list != NULL) {
            list->prev = NULL;
        }
    } else {
        prev->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = prev;
        }
    }

    if (curr == last) {
        last = prev;
    }

    free(curr);
    printf("Node at position %d deleted.\n", pos);
}

int main() {
    int ch, cnt;

    while (1) {
        printf("\n\n 1.Create the Doubly Linked List.");
        printf("\n 2.Display the Doubly Linked List.");
        printf("\n 3.Count the nodes in the Doubly Linked List.");
        printf("\n 4.Delete a node from the Doubly Linked List.");
        printf("\n 5.Exit the program.");
        printf("\n Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                cnt = countnode();
                printf("\n No. of nodes = %d\n", cnt);
                display();
                break;
            case 4:
                deletenode();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}