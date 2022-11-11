// quicksort for linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{

    int val;
    struct node* next;

};

typedef struct node* NodeAddress;

int a[] = {2, 7, 1, 9, 8, 4};
int length = 6;


void printList(struct node* n){

    while (n != NULL){
        printf("[%d]", n -> val);
        n = n -> next; 
    }
}




struct node* Arr2Link(int a[])
{   
    struct node * head; 
    head = malloc(sizeof(struct node*));
    head -> next = malloc(sizeof(struct node)); 
        head -> val = a[0]; 
        struct node* temp = head; 
    for (int i = 1; i< length; i++){
        
        temp -> next = malloc(sizeof(struct node)); 
        temp = temp -> next; 
        temp -> val = a[i];
    }
    printList(head);
    return head;

}



void swap(struct node* a, struct node* b)
{
int temp = a->val ; 
a->val = b->val;
b->val = temp; 
}

struct node* getTail(struct node* head)
{
    struct node* headref; 
    headref = head; 
    while (headref->next != NULL)
    {
        headref = headref->next; 
    }
return headref; 

}
struct node* partition(struct node* head, struct node* tail)
{
    struct node* prev = head;
    struct node* pivot = tail; 
    struct node* temp = head; 
    while (temp != tail)
    {
        if (temp -> val < pivot -> val)
        {
            swap(temp, prev);  
            prev = prev->next;   
        }
        temp = temp -> next; 
    }
    swap(pivot, prev); 

    return pivot; 
}

void quicksortRecursion(struct node*head, struct node* tail)
{   
    if (head < tail)
    {
        struct node* pivot = partition(head, tail);
        partition(head, pivot); 
        partition(pivot, tail);
    }
}

void quickSortLink(struct node* head)
{   
    struct node* tail = getTail(head); 
    quicksortRecursion(head, tail); 

}

int main(){
    struct node* head = Arr2Link(a);
    quickSortLink(head);
    printList(head);
    return 0;
}