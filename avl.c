#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int val;
    struct node* left; 
    struct node* right; 
    int balanceFactor;
};

typedef struct node* NodeAddress;


struct node* createNode(int val)
{
    NodeAddress ndoe = malloc(sizeof(struct node));
    node -> val = val; 
    node -> left = NULL;
    node-> right = NULL; 
    node-> height  = 1;
    return node; 
}

void rightRotate()

