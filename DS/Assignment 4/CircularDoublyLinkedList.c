#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct NODE {
    int data;
    struct NODE *next;
    struct NODE *prev;
};

typedef struct NODE node;

node *last = NULL;  // Pointer to the last node in the list

// Function to create a new node
node *getnode(int data) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = temp;  // Point to itself
    temp->prev = temp;  // Point to itself
    return temp;
}

// Function to create the doubly circular linked list
void create() {
    int data;
    char ch;
    node *temp;
    
    do {
        printf("\nEnter the data: ");
        scanf("%d", &data);
        temp = getnode(data);
        
        if (last == NULL) {
            last = temp;  // First node
        } else {
            temp->next = last->next;  // Point to first node
            temp->prev = last;  // Previous of new node is the last node
            last->next->prev = temp;  // Previous of first node is the new node
            last->next = temp;  // Last node points to new node
            last = temp;  // Update last node
        }
        
        printf("\nDo you want to enter more nodes? (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
}

// Function to display the doubly circular linked list
void display() {
    if (last == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    
    node *ptr = last->next;  // Start from the first node
    
    printf("\nDoubly Circular Linked List: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != last->next);  // Stop when we reach the first node again
    printf("\n");
}

// Main function
int main() {
    int ch;
    
    while (1) {
        printf("\n\n1. Create the Doubly Circular Linked List.");
        printf("\n2. Display the Doubly Circular Linked List.");
        printf("\n3. Exit the program.");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}