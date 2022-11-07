#include<stdio.h>

//selectionSort for arrays

int main() {

int a[] = {5, 4, 7, 2, 0, 1, 9, 8, 3, 6};
int length = sizeof(a)/sizeof(a[0]);


for (int i = 0; i < length - 1; i++) {
    int min_pos = i;

    for (int j = i + 1; j < length; j++)
        if (a[j] < a[min_pos]) min_pos = j;
    
    if (min_pos != i) {
        int temp = a[i]; 
        a[i] = a[min_pos];
        a[min_pos] = temp; 
    }
}

for (int i = 0; i < length; i++)
   printf("a[%d] = %d\n", i, a[i]);

return 0;
}


