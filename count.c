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
int count(Node *head){
    int count = 0;
    Node *temp = head;
    while (temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

int main(){
    Node *n1,*n2,*n3;

    n1 = create(10,NULL);
    n2 = create(20,NULL);
    n3 = create(30,NULL);

    n1->next = n2;
    n2->next = n3;

    printf("%d \n",count(n1));

    return 0;
}