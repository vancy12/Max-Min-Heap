// Online C compiler to run C program online
#include "header.h"

tree initBST(tree R, int length)
{
    R.root = (int *)malloc(sizeof(int) * length);
    R.size = length;
    return R;
}


tree insert(tree R, int data)
{
    int idx = 0;

    while (idx < R.size)
    {
        if (R.root[idx] == 0)
        {
            R.root[idx] = data;
            break;
        }
        idx++;
    }
    return R;
}

void maxHeapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // finds the largest of the three - root, left child and right child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

tree maxHeap(tree R)
{
    // calling maxHeapify function for parent nodes only
    // since R.size is length of array
    // but our array is zero-indexed so (R.size - 1)

    for (int i = (R.size-1) - 1 / 2; i >= 0; i--)
    {
        maxHeapify(R.root, R.size, i);
    }
    return R;
}

void minHeapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    
    // Swap and continue heapifying if root is not smallest
    if (smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

tree minHeap(tree R)
{
    for (int i = (R.size - 1) - 1 / 2; i >= 0; i--)
        minHeapify(R.root, R.size, i);

    return R;
}

void levelwise(tree R)
{
    for (int i = 0; i < R.size; i++)
    {
        printf("%d ", R.root[i]);
    }
    return;
}

void heapSortMax(tree R){
    int size = R.size;
    int arr[R.size];

    for(int i = 0; i <= R.size; i++){
        arr[i] = R.root[i];
    }

    while(size != 0){
        printf("%d ", arr[0]);
        arr[0] = arr[size - 1];
        size -= 1;
        for (int i = size / 2 - 1; i >= 0; i--){
            maxHeapify(arr, size, i);
        }
    }
    return;
}

void heapSortMin(tree R){
    int size = R.size;
    int arr[R.size];

    for(int i = 0; i <= R.size; i++){
        arr[i] = R.root[i];
    }

    while(size != 0){
        printf("%d ", arr[0]);
        arr[0] = arr[size - 1];
        size -= 1;
        for (int i = size / 2 - 1; i >= 0; i--){
            minHeapify(arr, size, i);
        }
    }
    return;
}
