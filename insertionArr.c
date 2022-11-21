#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[] = {12, 11, 10, 9, 8, 7, 6 ,5, 4, 3, 2, 1}; 
int n = sizeof(a)/sizeof(a[0]);

void swap(int* a, int* b)
{
    int temp = *a; 
    *a = *b;
    *b = temp;
}


void insertionSort(int* arr, int n)
{
    int prev; 
    int curr; 
    for (int i = 1; i < n; i++)
    {
        curr = arr[i]; 
        prev = i - 1; 

        while (arr[prev] > curr && prev >= 0)
        {
            arr[prev + 1] = arr[prev];
            prev = prev - 1; 
        }
        arr[prev + 1] = curr;
    }
}

/*
void printArr(int arr[], int n)
{
  
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
   
    printf("\n");
}
*/

int main()
{
    insertionSort(a, n);
    
    for (int i = 0; i < n; i++)
    printf("%d ", a[i]);

    return 0;
}