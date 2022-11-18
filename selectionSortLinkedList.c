#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//selection sort for linked list 

struct node{

        int val;
        struct node* next;

    };
    typedef struct node* nodeAddress;

int a[] = {2, 7, 1, 9, 8, 4}; 

int length = 6;

void printList(struct node* n){

    while (n != NULL){
        printf("[%d]", n -> val);
        n = n -> next; 
    }
}

// creating linked list out of an array
nodeAddress createLinkedList(int a[]){

    nodeAddress head = malloc(sizeof(struct node)); 

    //int length = sizeof(a)/sizeof(a[0]); 
    //  int length = 6; 
        head -> next = malloc(sizeof(struct node)); 
        head -> val = a[0]; 
        nodeAddress temp = head; 
    for (int i = 1; i< length; i++){
        
        temp -> next = malloc(sizeof(struct node)); 
        temp = temp -> next; 
        temp -> val = a[i];

    }
    printList(head); 
    return head; 
}

void swapNode(struct node *x, struct node *y)
{
    int temp = x->val;
    x->val = y->val;
    y->val = temp;
}

void selectionSort(nodeAddress head){
    nodeAddress min_pos;
    nodeAddress temp;
    nodeAddress headRef;
    headRef = head;
    while(head != NULL) {
        temp = head;
        min_pos = temp;

    while (temp != NULL) {
        
        if (temp -> val < min_pos -> val) min_pos = temp;
        
        temp = temp -> next;  


    }
    swapNode(head, min_pos);
    head = head->next;
}
printList(headRef);
}
        
    

int main(){
    nodeAddress head = createLinkedList(a); 
    printf("\n");
    selectionSort(head);
    return 0; 
    
}