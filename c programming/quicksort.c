#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void randarr(int arr[], int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand()%100;
    }
}

void printarr(int arr[], int size)
{
    int i;
    printf("{");

    for (i = 0; i < size - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d", arr[i]);
    printf("}");
}

int partition(int arr[], int l, int r)
{
    int temp, pivot = arr[l], pi = l;

    for (int i = l+1; i < r+1; i++)
    {
        if (arr[i]<=pivot)
        {
            l++;
            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[l];
    arr[l] = pivot;
    arr[pi] = temp;
    return l;
}

void quick_sort(int arr[], int l, int r)
{
    int pivot = partition(arr, l, r);
    if (l<r)
    {
        quick_sort(arr, l, pivot-1);
        quick_sort(arr, pivot+1, r);        
    }
}

int main()
{
    srand(time(NULL));
    int size = rand()%21 + 10;
    int arr[size];

    randarr(arr, size);
    printarr(arr, size);
    quick_sort(arr, 0, size-1);
    printf("\n");
    printarr(arr, size);

    return 0;
}