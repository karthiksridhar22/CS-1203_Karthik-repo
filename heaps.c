#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n = 10; 

int* createArr(int n){
    int* arr = malloc(sizeof(int)*n); 
    srand(time(NULL));
    for (int i=0; i < n; i++){
        int num = rand() % 10000;
        arr[i] = num;
            }
    return arr;         
    }

void swap(int* a, int* b){
    
    int temp =  *a; 
    *a = *b; 
    *b = temp; 
    
}

void heapify(int* arr, int n, int p){
int c1 = 2*p + 1;
int c2 = 2*p + 2; 
int min = p; 

if(arr[c1] < arr[min] && c1 < n) min = c1;

if (c2 < n && arr[c2] < arr[min]) min = c2; 

if (min == p) return;

else{
    swap(&arr[min], &arr[p]);
    heapify(arr, n, min); 
}
}

int* genHeap(int* arr, int n){

    //start from the last parent and sort from bottom to top

    int pEnd = n/2 - 1; 
    for (int i = pEnd; i ==0; i--){
        heapify(arr, n, i); 
    }
    return arr; 
}

void printList(int* arr){
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
}
int main(){

    int* arr = createArr(n);
    printList(arr);
    printf("/n");
    int* a = genHeap(arr, n);
    printList(a);
    return 0; 
}