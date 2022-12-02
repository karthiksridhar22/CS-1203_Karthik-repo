#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int val;
    struct node* left; 
    struct node* right; 
    int height;
};

typedef struct node* NodeAddress;


NodeAddress createNode(int val)
{
    NodeAddress node = malloc(sizeof(struct node));
    node -> val = val; 
    node -> left = NULL;
    node-> right = NULL; 
    node-> height  = 1;
    return node; 
}

// get the height of the node from the root note
int height(struct node* node)
{
    if (node == NULL)
    return 0;
    return node-> height;
}

int max(int a, int b)
{
    
    return (a > b) ? a : b;
    
}



NodeAddress right_rotate(NodeAddress node)
{
    NodeAddress x = node -> left;
    NodeAddress temp = x -> right;

    x -> right = node;
    node -> left = temp;

    node -> height = max(height(node->left), height(node->right)) + 1;
    x -> height = max(height(x->left), height(x->right)) + 1;

    return x; 
}

NodeAddress left_rotate(NodeAddress node)
{
    NodeAddress x = node -> right;
    NodeAddress temp = x->left;

    x -> left = node;
    node->right = temp;

    node -> height = max(height(node->left), height(node->right)) + 1;
    x -> height = max(height(x->left), height(x->right)) + 1;

    return x; 
   
}

int getBalanceFactor(struct node* node)
{
    if (node == NULL)
        return 0;
    return(height(node->left) - height(node -> right) );
}

NodeAddress insertNode(NodeAddress node, int val)
{
    if (node == NULL)
       return createNode(val);
    
    // finding the right place to insert the node
    if (val < node -> val)
    {
        node -> left = insertNode(node->left, val);
    }
    else if (val >= node -> val)
    {
        node -> right = insertNode(node->right, val);
    }


    // balance the tree

    node -> height = max(height(node->left), height(node -> right)) + 1;

    int balanceFactor = getBalanceFactor(node);
    
    if (balanceFactor > 1 && val < node -> left -> val)
    {
        return right_rotate(node);
    }

    if (balanceFactor < -1 && val > node->right->val)
    {
        return left_rotate(node);
    }

    if (balanceFactor > 1 && val > node->left->val) {
    node->left = left_rotate(node->left);
    return right_rotate(node);
  }

    if (balanceFactor < -1 && val < node->right->val) {
    node->right = right_rotate(node->right);
    return left_rotate(node);
  }

  return node;
}

/*
NodeAddress delete_node(NodeAddress node, int val )
{
    //find the node to be deleted
    if (node == NULL)
        return node;
    
    if (val < node -> val)
    {
      node -> left =  delete_node(node->left, val);
    }

    else if(val > node -> val)
    {
        node -> right = delete_node(node->right, val);
    } 


}
*/

void printPreOrder(NodeAddress root)
{
    if (root != NULL)
    {
        printf(" %d ", root->val );
        printPreOrder(root->left);
        printPreOrder(root->right);

    } 
}

int main()
{
    NodeAddress root = NULL;
    insertNode(root, 5);
    return 0;
}

