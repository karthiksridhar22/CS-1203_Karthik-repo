#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 
int a[] = {39, 67, 65, 12, 34, 19, 87, 43, 12, 97, 98, 99};
int n = sizeof(a)/sizeof(a[0]);

void printArr(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]); 
    }
}



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
int max = p; 

if(arr[c1] > arr[max] && c1 < n) max = c1;

if (c2 < n && arr[c2] > arr[max]) max = c2; 

if (max == p) return;

else{
    swap(&arr[max], &arr[p]);
    heapify(arr, n, max); 
}
}

int* genHeap(int* arr, int n){

    //start from the last parent and sort from bottom to top

    int pEnd = n/2 - 1; 
    for (int i = pEnd; i >=0; i--){
        heapify(arr, n, i); 
    }
    return arr; 
}

void printList(int* arr){
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
}

void heapSort(int*a, int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
    heapify(a, n, i);

    for (int i = n-1; i >=0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}




int main(){
heapSort(a, n);
printArr(a, n);

    return 0; 
}

