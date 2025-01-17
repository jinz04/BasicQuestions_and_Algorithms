#include <stdio.h>
#include <stdlib.h>
void genRand(int *arr, int n, int min, int max)
{
    for(int i=0;i<n;i++)
    arr[i]= rand()%(max-min+1)+min;
}
void Sort(int *arr, int n)
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
int binarySearch(int *arr, int low, int high, int key)
{
     if(low>high)
        return -1;
    int mid= low+(high-low)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        return binarySearch(arr, low, mid-1, key);
    else
        return binarySearch(arr, mid+1, high, key);
}
int main()
{
    int arr[100], n, key;
    printf("Enter the number of array elements: \n");
    scanf("%d", &n);
    genRand(arr,n,1,100);
    Sort(arr,n);
    printf("The array is: \n");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
        
    printf("\nEnter the element to be searched: \n");
    scanf("%d",&key);
    int res= binarySearch(arr,0,n-1,key);
    if(res!=-1)
        printf("Element found at position %d\n",res+1);
    else
        printf("Element not found\n");
    return 0;

}