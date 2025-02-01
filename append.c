#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *create(int item,Node *next){
    Node *new = (Node *) malloc(sizeof(Node));
    if (new==NULL){
        printf("Error!");
        exit(1);
    }
    new->data = item;
    new->next = next;
    
    return new;
}

Node *prepend(Node *head,int item){
    Node *new = create(item,head);

    return new;
}

Node *append(Node *head,int item){ 
    Node *new = create(item,NULL);

    if (head == NULL){
        return new;
    }

    Node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;

    return head;
}

void printll(Node *head){
    Node *temp = head;
    while (temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node *n1,*head;

    n1 = create(10,NULL);
    head = n1;
    printll(head);

    head = prepend(head,20);
    printll(head);

    head = append(head,30);
    printll(head);
 
    return 0;
}