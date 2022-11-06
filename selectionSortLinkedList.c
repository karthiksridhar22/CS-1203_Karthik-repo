#include<stdio.h>
#include<stdlib.h>
struct node{

        int val;
        struct node* next;

    };
    typedef struct node* nodeAddress;

int a[] = {2, 7, 1, 9, 8, 4}; 

int length = 6;

void printList(struct node* n){

    while (n != NULL){
        printf("%d ->", n -> val);
        n = n -> next; 
    }
}

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
     
     while(head != NULL) {
    nodeAddress min_pos = head;
    nodeAddress temp = head;
    nodeAddress headRef = head;
    for (int i = 0; i < length; i++){
        temp = temp -> next; 
        if (temp -> val < min_pos -> val) {
        swapNode(min_pos, temp);
        head = head -> next;  }


    }
}
head = headRef
printList(head);
}
        
    

int main(){
    nodeAddress head = createLinkedList(a); 

    return 0; 
}