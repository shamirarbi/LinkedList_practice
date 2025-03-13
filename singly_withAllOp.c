#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *next;
};

void display(Node *head){
    Node *temp = head;
    while (temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main(){
    Node *head,*n1,*n2,*n3;

    n1 = (Node *) malloc(sizeof(Node));
    n1->data = 7;
    n1->next = NULL;

    head = n1;

    n2 = (Node *) malloc(sizeof(Node));
    n2->data = 9;
    n2->next = NULL;

    n3 = (Node *) malloc(sizeof(Node));
    n3->data = 11;
    n3->next = NULL;

    n1->next = n2;
    n2->next = n3;

    printf("The linked list is : ");
    display(head);

    //first insert
    Node *new = (Node *) malloc(sizeof(Node));
    new->data = 3;
    new->next = NULL;

    new->next = head;
    head = new;

    printf("after first insert : ");
    display(head);

    //last insert
    Node *new2 = (Node *) malloc(sizeof(Node));
    new2->data = 5;
    new2->next = NULL;

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new2;

    printf("after last insert : ");
    display(head);

    //middle insert by position
    Node *new3 = (Node *) malloc(sizeof(Node));
    new3->data = 13;
    new3->next = NULL;

    int pos = 3;
    Node *temp2 = head;
    for (int i = 1; i < pos-1; i++){
        temp2 = temp2->next;
    }
    new3->next = temp2->next;
    temp2->next = new3;

    printf("after middle insert by position (3) : ");
    display(head);

    //middle insert by value
    Node *new4 = (Node *) malloc(sizeof(Node));
    new4->data = 8;
    new4->next = NULL;
    Node *temp3 = head;
    int value = 11;
    while(temp3 != NULL && temp3->data != value){
        temp3 = temp3->next;
    }
 
    new4->next = temp3->next;
    temp3->next = new4;

    printf("after middle insert by value (11) : ");
    display(head);
    
    //first delete
    Node *temp4 = head;
    head = head->next;
    free(temp4);

    printf("after first delete : ");
    display(head);

    //last delete
    Node *temp5 = head;
    while(temp5->next->next != NULL){
        temp5 = temp5->next;
    }

    Node *temp6 = temp5->next;
    temp5->next = NULL;
    free(temp6);

    printf("after last delete : ");
    display(head);

    //middle delete by position
    Node *temp7 = head;
    int pos2 = 3;
    for (int i = 1; i < pos2-1; i++){
        temp7 = temp7->next;
    }
    Node *temp8 = temp7->next;
    temp7->next = temp8->next;
    free(temp8);

    printf("after middle delete by position (3) : ");
    display(head);

    //middle delete by value
    Node *temp9 = head;
    int value2 = 13;
    while(temp9->next != NULL && temp9->next->data != value2){
        temp9 = temp9->next;
    }
    Node *temp10 = temp9->next;
    temp9->next = temp10->next;
    free(temp10);

    printf("after middle delete by value (9) : ");
    display(head);

    return 0;
}