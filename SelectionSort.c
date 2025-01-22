#include <stdio.h>
#include <stdlib.h>
void genRand(int *a, int n, int min, int max)
{
    for(int i=0;i<n;i++)
    a[i]=rand()%(max-min+1)+min;
}

void selectionSort(int *a, int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIdx=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minIdx])
            {
                minIdx=j;
            }
        }
        int temp= a[i];
        a[i]=a[minIdx];
        a[minIdx]=temp;
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
    selectionSort(a,n);
    printf("\nSorted array: \n");
    for(int i=0;i<n;i++)
    printf("%d ", a[i]);
    printf("\n");
}