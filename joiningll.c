#include<stdio.h>
#include<stdlib.h>

typedef struct list List;

struct list{
    int data;
    List *next;
};

void display(List *head){
    List *temp = head;
    while (temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    
    List *n1,*n2,*n3,*n4,*lst1,*lst2,*lst3;

    n1 = (List *) malloc(sizeof(List));
    n1->data = 3;
    n1->next = NULL;

    lst1 = n1;

    n2 = (List *) malloc(sizeof(List));
    n2->data = 5;
    n2->next = NULL;

    n1->next = n2;

    display(lst1);

    n3 = (List *) malloc(sizeof(List));
    n3->data = 7;
    n3->next = NULL;

    lst2 = n3;

    n4 = (List *) malloc(sizeof(List));
    n4->data = 9;
    n4->next = NULL;

    n3->next = n4;

    display(lst2);

    List *temp = lst1;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = lst2; // Correctly link the end of the first list to the second list

    lst3 = lst1; // Start from the first list

    display(lst3); // Display the combined list starting from lst1


    

    return 0;
}
