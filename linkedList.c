
    #include<stdio.h>
    #include<stdlib.h>
    struct node{

        int val;
        struct node* next;

    };
    typedef struct node* nodeAddress;

    void printList(struct node* n){

    while (n != NULL){
        printf("%d ->", n -> val);
        n = n -> next; 

}
}

    nodeAddress createLinkedList(){
        int n;
        printf("enter the size of the list\n");
        scanf("%d",&n);
        nodeAddress head = malloc(sizeof(struct node));
        nodeAddress temp = head;
        printf("enter values\n");
        scanf(" %d\n",&temp->val);
        for(int i=1;i<n;i++)
        {
            
            temp->next = malloc(sizeof(struct node));
            temp = temp->next;
            scanf(" %d\n",&temp->val);
        }
     
        printList(head);

        return head;
    }
    
    void reverseLinkedList(struct node* head){
        nodeAddress prev = NULL;
        nodeAddress curr = head; 
        nodeAddress next = NULL;

        
        
        while (curr != NULL) {
            next = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = next;  
        }
        head = prev;

        printList(head);
    }
    
    /*
    void chunkReverse(head, k){

        int i = 0; 
        nodeAdress swapAddress;
        nodeAddress prev = NULL;
        nodeAddress curr = head; 
        nodeAddress next = NULL;
        
        while (curr!= NULL ) {
            if (i%k != 0){
            next = curr -> next; 
            prev = curr; 
            curr = next; 
            i = i + 1;
            }
            else{

            }
        }


    }
    */

    int main(){
        nodeAddress head;
        head = createLinkedList();
        printf(" \n");
        reverseLinkedList(head);
    return 0;
       
    }






