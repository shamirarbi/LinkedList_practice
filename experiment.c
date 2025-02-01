#include<stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *next;
};

Node *create(int item,Node *next){

    Node *new = (Node*)malloc(sizeof(Node));

    if (new == NULL){
        printf("Error!");
        exit (1);
    }

    new->data = item;
    new->next = next;

    return new;
}

Node *prepend(Node *head,int item){
    Node *new = create(item,head);

    return new;
}

int main(){
    
    Node *n1,*n2,*n3,*n4,*head;

    n1 = create(10, NULL);
    head = n1;
    n2 = create(20, NULL);
    n3 = create(30, NULL);
    n4 = prepend(n1,40);

    n1->next = n2;
    n2->next = n3; 
    //n5->next = n1;

    //Node *head;
    head = n4;
    
    int i = 1;
    while (head != NULL){
        printf("data %d >> %d\n",i,head->data);       
        head = head->next;
        i++;
    }

    return 0;
}