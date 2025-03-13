#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *creatnode(int data) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertfirst(Node **head, int data) {
    Node *newnode = creatnode(data);
    if (newnode == NULL) return;
    newnode->next = *head;
    *head = newnode;
}

void lastinsert(Node **head, int data) {
    Node *newnode = creatnode(data);
    if (newnode == NULL) return; 

    if (*head == NULL) { 
        *head = newnode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) { 
        temp = temp->next;
    }

    temp->next = newnode; 
}


void insertmid(Node **head, int data, int pos) {
    if (*head == NULL || pos <= 1) {
        insertfirst(head, data);
        return;
    }

    Node *newnode = creatnode(data);
    if (newnode == NULL) return;

    Node *temp = *head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == NULL) {
            printf("Position is out of range.\n");
            free(newnode);
            return;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deletefirst(Node **head) {
    if (*head == NULL) {
        printf("Nothing to delete.\n");
        return;
    }

    Node *temp = *head;
    *head = temp->next;
    free(temp);
}

void deletelast(Node **head) {
    if (*head == NULL) {
        printf("Nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deletemid(Node **head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->data == data) {
        deletefirst(head);
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element not found.\n");
        return;
    }

    Node *hold = temp->next;
    temp->next = hold->next;
    free(hold);
}

void display(Node *head) {
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

int main() {
    Node *head, *n1, *n2, *n3;

    n1 = creatnode(7);
    head = n1;
    n2 = creatnode(9);
    n3 = creatnode(11);
    n1->next = n2;
    n2->next = n3;

    printf("The linked list is : ");
    display(head);

    printf("Adding 5 at the beginning.\n");
    insertfirst(&head, 5);
    display(head);

    printf("Adding 12 at the end.\n");
    lastinsert(&head, 12);
    display(head);

    printf("Inserting 4 at position 3.\n");
    insertmid(&head, 4, 3);
    display(head);

    printf("Deleting first node.\n");
    deletefirst(&head);
    display(head);

    printf("Deleting last node.\n");
    deletelast(&head);
    display(head);

    int dlt = 9;
    printf("Deleting node with data %d.\n", dlt);
    deletemid(&head, dlt);
    display(head);

    return 0;
}

