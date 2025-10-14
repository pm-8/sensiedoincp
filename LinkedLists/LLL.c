#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void insertAtBeginning(struct Node** head, int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = (*head);
    (*head) = newNode;
    return;
}
void insertAtEnd(struct Node** head, int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = (*head);
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp -> next = newNode;
    return;
}
void insertAfterPPos(struct Node** head, int p, int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    if(*head == NULL){
        *head = newNode;
        newNode -> next = NULL;
        return;
    }
    struct Node* temp = (*head);
    for(int i=0; i<p-1 && temp != NULL; i++){
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("The previous node is null.\n");
        free(newNode);
        return;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
    return;
}
void deleteNodeFromStart(struct Node** head){
    if(*head == NULL){
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head) -> next;
    free(temp);
    return;
}
void deleteNodeFromEnd(struct Node** head){
    if(*head == NULL){
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if(temp -> next == NULL){
        free(temp);
        *head = NULL;
        return;
    }
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = NULL;
    return;
}
void deleteNodeAtPos(struct Node** head, int p){
    if(*head == NULL){
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if(p == 0){
        *head = (*head) -> next;
        free(temp);
        return;
    }
    for(int i=0; i<p-1 && temp != NULL; i++){
        temp = temp -> next;
    }
    if(temp == NULL || temp -> next == NULL){
        printf("The position is invalid.\n");
        return;
    }
    struct Node* nodeToDelete = temp -> next;
    temp -> next = nodeToDelete -> next;
    free(nodeToDelete);
    return;
}
int main(){
    struct Node* head = NULL;
    // insertAtBeginning(&head, 1);
    // insertAtBeginning(&head, 2);
    // insertAtBeginning(&head, 3);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    struct Node* ptr = head;
    while(ptr != NULL){
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    insertAfterPPos(&head, 2, 4);
    ptr = head;
    printf("after insertion at position 2:\n");
    while(ptr != NULL){
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    // Free allocated memory
    deleteNodeFromStart(&head);
    printf("after deletion from start:\n");

    ptr = head;
    while(ptr != NULL){
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    deleteNodeFromEnd(&head);
    printf("after deletion from end:\n");   
    ptr = head;
    while(ptr != NULL){
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    deleteNodeAtPos(&head, 1);
    printf("after deletion at position 1:\n");
    ptr = head;
    while(ptr != NULL){
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return 0;
}