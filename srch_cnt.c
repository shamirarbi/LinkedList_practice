#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *create (int item,Node *next){
    Node *new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Memory error\n");
        exit(1);
    }
    new->data = item;
    new->next = next;

    return new;
}

Node *search(Node *head,int item){
    Node *temp = head;
    int count = 0;
    while (temp != NULL){
        count++;
        if (temp->data == item){
            printf("Item found at position %d\n",count);
            return temp;
        }
        temp = temp->next;
    }
    printf("Item not found\n");
    return NULL;
}

int main(){
    Node *n1,*n2,*n3,*n4,*head;

    n1 = create(10,NULL);
    head = n1;
    n2 = create(20,NULL);
    n3 = create(30,NULL);
    n4 = create(40,NULL);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Node *item = search(head,40);

    return 0;
}