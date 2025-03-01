#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
    Node *pre;
};

void display(Node *head){
    Node *temp = head;
    while (temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node *head,*n1,*n2,*n3;

    n1 = (Node *) malloc(sizeof(Node));
    n1->data = 7;
    n1->next = NULL;
    n1->pre = NULL;

    head = n1;

    n2 = (Node *) malloc(sizeof(Node));
    n2->data = 9;
    n2->next = NULL;
    n2->pre = NULL;

    n3 = (Node *) malloc(sizeof(Node));
    n3->data = 11;
    n3->next = NULL;
    n3->pre = NULL;

    n1->next = n2;
    n2->pre = n1;
    n2->next = n3;
    n3->pre = n2;

    display(head);

    Node *new = (Node *) malloc(sizeof(Node));
    printf("Enter the data for the new node: ");
    scanf("%d", &new->data); // Get the data for the new node from the user
    new->next = NULL;
    new->pre = NULL;

    int searchValue; // Variable to hold the value to search for
    printf("Enter the value to search for: ");
    scanf("%d", &searchValue); // Get the value from the user

    Node *temp = head;
    while(temp != NULL && temp->data != searchValue){
        temp = temp->next;
    }

    if (temp != NULL) { // If the value is found
        new->pre = temp;
        new->next = temp->next;
        if (temp->next != NULL) {
            temp->next->pre = new;
        }
        temp->next = new;
    } else {
        printf("Value %d not found in the list.\n", searchValue);
        free(new); // Free the allocated memory for the new node if not inserted
    }

    display(head);

    return 0;
}
