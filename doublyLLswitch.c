#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *pre;
    struct node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new->data = data;
    new->pre = NULL;
    new->next = NULL;
    return new;
}

// Function to display the list
void display(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert at the beginning
void firstInsert(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->pre = newNode;
    *head = newNode;
}

// Function to insert at the end
void lastInsert(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->pre = temp;
}

// Function to insert at a specific position
void midInsert(Node **head, int data, int pos) {
    if (pos == 1 || *head == NULL) {
        firstInsert(head, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->pre = newNode;
    }
    temp->next = newNode;
    newNode->pre = temp;
}

// Function to delete the first node
void firstDelete(Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->pre = NULL;
    }
    free(temp);
}

// Function to delete the last node
void lastDelete(Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a specific position
void midDelete(Node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos == 1) {
        firstDelete(head);
        return;
    }
    Node *temp = *head;
    for (int i = 1; i < pos && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    Node *hold = temp->next;
    temp->next = hold->next;
    if (hold->next != NULL) {
        hold->next->pre = temp;
    }
    free(hold);
}

// Main function with switch-case menu
int main() {
    Node *head = NULL;
    int choice, data, pos;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                firstInsert(&head, data);
                printf("\nUpdated List: ");
                display(head);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                lastInsert(&head, data);
                printf("\nUpdated List: ");
                display(head);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                midInsert(&head, data, pos);
                printf("\nUpdated List: ");
                display(head);
                break;
            case 4:
                firstDelete(&head);
                printf("\nUpdated List: ");
                display(head);
                break;
            case 5:
                lastDelete(&head);
                printf("\nUpdated List: ");
                display(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                midDelete(&head, pos);
                printf("\nUpdated List: ");
                display(head);
                break;
            case 7:
                printf("\nList: ");
                display(head);
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
