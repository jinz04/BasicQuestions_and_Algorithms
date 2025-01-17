#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void genRand(int *arr, int n, int min, int max)
{
    for(int i=0;i<n;i++)
    {
        arr[i]= rand()%(max-min+1)+min;
    }
}
void bubbleSort(int *arr, int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int arr[500],n;
    clock_t start,end;
    double time;
    printf("Enter the number of array elements: \n");
    scanf("%d",&n);
    srand(0);
    genRand(arr,n,1,100);
    printf("Unsorted array: \n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    start=clock();
    bubbleSort(arr,n);
    end= clock();
    time= ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nSorted array: \n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nTime taken: %f\n", time);
    return 0;
}