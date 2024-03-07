// Online C compiler to run C program online
#include "header.h"

tree initBST(tree R, int length){
    R.root = (int*)malloc(sizeof(int)*length);
    R.size = length;
    return R;
}

void initStack(stack* S, int length){
    S->top = -1;
    S->size = length;
    S->array = (int*)malloc(sizeof(int)*length);
}


tree insertBST(tree R, int data){
    int idx = 0;
    
    // for(int i =0; i < R.size; i++){
    //  R.root[i] = 0;
    // }
    
    while(idx < R.size){
        if(R.root[idx] == 0){
            R.root[idx] = data;
            break;
        }
        else if(data < R.root[idx]){
            idx = 2*idx+1;
        }
        else if(data > R.root[idx]){
            idx = 2*idx+2;
        }
    }
    return R;
}

void maxHeapify(int arr[], int n, int i) {
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
  }
}

tree maxHeap(tree R){
    for (int i = R.size / 2 - 1; i >= 0; i--){

        maxHeapify(R.root, R.size, i);
    
    }
    return R;
}

void minHeapify(int arr[], int n, int i) {
  // Find largest among root, left child and right child
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] < arr[smallest])
    smallest = left;

  if (right < n && arr[right] < arr[smallest])
    smallest = right;

    // Swap and continue heapifying if root is not smallest
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
  }
}

tree minHeap(tree R){
    for (int i = R.size / 2 - 1; i >= 0; i--)
      minHeapify(R.root, R.size, i);
    
    return R;
}

void levelwise(tree R){
    for(int i = 0; i < R.size; i++){
        printf("%d ", R.root[i]);
    }
    return;
}


int isFull(stack S){
    return(S.top == S.size);
}
int isEmpty(stack S){
    return(S.top == -1);
}

void push(stack* S, int index){
    if(isFull(*S))
        return;
    S->top += 1;
    S->array[S->top] = index;
    return;
}

int pop(stack* S){
    if(isEmpty(*S))
        return 0;
    int p = S->array[S->top];
    S->top -= 1;
    // printf("Value of top is:%d", S->top);
    return p;
}
