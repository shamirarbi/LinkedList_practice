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

// Node *remove_node(Node *head, int item){
//     if (head == NULL){
//         return NULL;
//     }
//     if (head->data == item){
//         Node *temp = head->next;
//         free(head);
//         return temp;
//     }
//     Node *current = head;
//     while (current->next != NULL){
//         if (current->next->data == item){
//             Node *temp = current->next;
//             current->next = current->next->next;
//             free(temp);
//             return head;
//         }
//         current = current->next;
//     }
//     return head;
// }


int main(){
    
    

    return 0;
}