#include <stdio.h>
#include <stdlib.h>

void genRand(int *a,int n, int min, int max)
{
    for(int i=0;i<n;i++)
    a[i]=rand()%(max-min+1)+min;
}

void merge(int *a,int low, int mid, int high)
{
    int i,j,k,n1,n2;
    n1=mid-low+1; //no of elements in left subarray a[low....mid]
    n2=high-mid; //no of elements in right subarray a[mid+1....high]
    int leftArr[n1],rightArr[n2]; //temporary arrays
    for(i=0;i<n1;i++)
    leftArr[i]= a[low+i]; //copy left part of partitioned elements to left subarray
    for(j=0;j<n2;j++)
    rightArr[j]=a[mid+1+j]; //copy right part of partitioned elements to right subarray

    //merge back to array a[low...high]
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2)
    {
        if(leftArr[i]<rightArr[j])
        {
            a[k]=leftArr[i];
            i++;k++;
        }
        else{
            a[k]=rightArr[j];
            j++;k++;
        }
    }
    while(i<n1) //if any remaining elements in left subarray
    {
        a[k]=leftArr[i];
        i++;k++;
    }
    while(j<n2)
    {
        a[k]=rightArr[j]; //if any remaining elements in right subarray
        j++;k++;
    }
}

void mergeSort(int *a, int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
    int a[100],n;
    srand(0);
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    genRand(a,n,1,100);
    printf("Unsorted array: \n");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    mergeSort(a,0,n-1);
    printf("\nSorted array: \n");
    for(int i=0;i<n;i++)
    printf("%d ", a[i]);
    printf("\n");
}