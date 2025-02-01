#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *create(int item,Node *next){
    Node *new = (Node *) malloc(sizeof(Node));
    if (new == NULL)
    {
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

int main(){
    Node *n1,*n2,*n3,*head;

    n1 = create(10,NULL);
    head = n1;

    head = prepend(n1,15);

    //n2 = head;
    printf("1 >> %d\n",head->data);

    n2 = head->next;
    printf("2 >> %d\n",n2->data);

    return 0;
}