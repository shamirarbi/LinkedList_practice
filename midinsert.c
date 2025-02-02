#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *create(int item,Node *next){
    Node *new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Error!");
        exit(1);
    }
    new->data = item;
    new->next = next;

    return new;
}

Node *insert(Node *head, int item, int position) {
    Node *new = create(item, NULL);

    if (position == 0) {
        new->next = head;
        return new;
    }

    Node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    new->next = temp->next;
    temp->next = new;

    return head;
}

int main(){
    Node *n1,*n2,*n3,*head;

    n1 = create(10,NULL);
    head = n1;
    n2 = create(20,NULL);
    n3 = create(30,NULL);

    n1->next = n2;
    n2->next = n3;

    insert(head, 15, 3);

    Node *temp = head;

    while (temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
    return 0;
}