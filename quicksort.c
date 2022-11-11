#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 10; // size of linked list

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

int partition(int* arr, int low, int high)
{

    int pivot_val = arr[high];
    int i = low;
    for (int j = low; j < high; j++){

        if (arr[j] < pivot_val)
        {
            swap(&arr[j], &arr[i]);
            i++; 
        }

    }
    
    swap(&arr[i], &arr[high]); 
return i; 
}


void quicksort_recursion(int* arr, int low, int high){

    if (low < high)
    {
    int pivot = partition(arr, low, high); 
    quicksort_recursion(arr, low, pivot - 1);
    quicksort_recursion(arr, pivot + 1, high);
    }
}

void quicksort(int* arr){
    quicksort_recursion(arr, 0, n);

}


int main(){

int* arr = createArr(n); 

quicksort(arr); 

for (int i = 0; i < n; i++){
    printf( "%d ", arr[i]);
}

    return 0;
}