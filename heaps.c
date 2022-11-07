#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n = 10; 

int* createArr(int n){
    int* arr = malloc(sizeof(int)*n); 
    for (int i=0; i < n; i++){
        int num = rand() % 10000;
        arr[i] = num;
            }
    return arr;         
    }

void swap(int* a, int* b){
    
    int temp = * a; 
    *a = *b; 
    *b = temp; 
    
}

int main(){
    int* a = createArr(n);
    /*
    for (int i = 0; i < n; i++) {
        printf(" %d ", a[i]);
        i = i+1; }
        */
    
    return 0; 
}