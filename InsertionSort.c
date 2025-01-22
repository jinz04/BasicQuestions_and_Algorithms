#include <stdio.h>
#include <stdlib.h>
 
void genRand(int *a, int n, int min, int max)
{
    for(int i=0;i<n;i++)
        a[i]= rand()%(max-min+1)+min;
}
void insertionSort(int *a, int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
            //elements greater than key are shifted one position to the right
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    int a[100],n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    genRand(a,n,1,100);
    printf("Unsorted array: \n");
    for(int i=0;i<n;i++)
    printf("%d ", a[i]);
    insertionSort(a,n);
    printf("\nSorted array: \n");
    for(int i=0;i<n;i++)
    printf("%d ", a[i]);
    printf("\n");
}