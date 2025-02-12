#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Lomuto partition scheme (corrected version)
int partition(int *a, int start, int end) {
    int pivot = a[end]; // Choosing last element as pivot
    int i = start - 1;  

    for (int j = start; j < end; j++) {
        if (a[j] < pivot) { 
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[end]); 
    return i + 1; 
}

void quickSort(int *a, int start, int end) {
    if (start < end) {
        int pIndex = partition(a, start, end);
        quickSort(a, start, pIndex - 1);
        quickSort(a, pIndex + 1, end);
    }
}

void genRand(int *a, int n, int min, int max) {
    for(int i = 0; i < n; i++)
        a[i] = rand() % (max - min + 1) + min;
}

int main() {
    int a[100], n;
    srand(0);
    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    genRand(a, n, 1, 100);
    printf("Unsorted array: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    quickSort(a, 0, n - 1);

    printf("\nSorted array: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n");
    return 0;
}
