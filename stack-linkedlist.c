#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// stack-linkedlist

struct node{
    int val;
    struct node* next;
};

typedef struct node* nodeAddress;

nodeAddress top = NULL;
nodeAddress push(int val){
    nodeAddress node = malloc(sizeof(struct node));
    node->val = val;
    node->next = top;
    top = node;

    return top;
}

nodeAddress pop(){
    if (top == NULL){
        printf("stack empty");
        return NULL;
    }
    nodeAddress temp = top;
    top = top->next;
    free(temp);

    return top;
}

void display(nodeAddress top){
    nodeAddress temp = top;
    while(temp){
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

int main(){
    nodeAddress top =  push(8);
    top = push(7);
    top = push(15);
    top = push(23);
    display(top);
    top = pop();
    printf("\n");
    display(top);
    return 0;
}