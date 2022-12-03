#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int val;
    struct node** next; 
    int level;
};

typedef struct node* NodeAddress; 

NodeAddress CreateRoot(int val){
    NodeAddress root = malloc(sizeof(struct node));
    root -> val = val;
    root -> next = malloc(sizeof(struct node) * 2);
    root -> next[0] = malloc(sizeof(struct node));
    root -> next[1] = malloc(sizeof(struct node));
    root->level = 2;
    return root;
}

NodeAddress insertNode(NodeAddress root, int val){
    if (root == NULL)
    return CreateRoot(val);

    NodeAddress temp = root; 
    while(temp){
        temp = temp ->  next[0];
    }
    srand(time(NULL));
    int n = rand() %10;
    if ( n <= 2){
        temp = malloc(sizeof(struct node) * 2);
        temp->level = 2;
        temp -> next[0] = malloc(sizeof(struct node));
        temp -> next[1] = malloc(sizeof(struct node));
    }
    else{
        temp = malloc(sizeof(struct node));
        temp->val = val;
        temp->next[0] = malloc(sizeof(struct node));
        temp->next[1] = malloc(sizeof(struct node));
        temp->level = 1; 
    }
    return root;
}

NodeAddress CreateSkip(){
    NodeAddress root;
    int num;
    printf("enter the size of your skiplist");
    scanf("%d", &num);
    int val;        
    for (int i = 0; i<num; i++){
        printf("enter the value for node %d", i);
        scanf(" %d\n", &val);
        insertNode(root, val);
    }
    
    struct node * *list =calloc(num, sizeof (struct node));
    NodeAddress temp = root;
    int i = 0;
    while (temp){
        if (temp->level ==2){
            list[i] = temp;
        }
        i = i+1;
        temp = temp ->next[0];
    }
    i = 0;
    while(list[i] != 0){
        list[i]->next[1] = list[i+1];
        i = i + 1;
    }
    return root;
}

void printList(struct node* n){

    while (n != NULL){
        NodeAddress temp = n;
        printf("%d ->", temp -> val);
        temp = temp -> next[0]; 
    }
}

int main(){
NodeAddress root = CreateSkip();
printf("%d", root->val);
return 0;
}



