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

void heapify(int arr[], int size, int heap)
{
    int temp;
    int largest = heap;
    int l = heap*2 +1;
    int r = heap*2 +2;

    if (l < size && arr[largest] < arr[l])
    {
        largest = l;
    }
    if (r < size && arr[largest] < arr[r])
    {
        largest = r;
    }
    if (largest != heap)
    {
        temp = arr[heap];
        arr[heap] = arr[largest];
        arr[largest] = temp;

        heapify(arr, size, largest);
    }
}

void heap_sort(int arr[], int size)
{
    int temp, heap;

    for (heap = size/2 -1; heap>=0; heap--)
    {
        heapify(arr, size, heap);
    }

    for (heap = size -1; heap > 0; heap--)
    {
        temp = arr[0];
        arr[0] = arr[heap];
        arr[heap] = temp;

        heapify(arr, heap, 0);
    }
}

int main()
{
    srand(time(NULL));

    int size = rand() % 21 + 10;
    int arr[size];

    randarr(arr, size);
    printarr(arr, size);
    printf("\n");

    heap_sort(arr, size);
    printarr(arr, size);

    return 0;
}
