#include <stdio.h>
#include <malloc.h>

int left(int i)
{ 
	return i<<1 + 1; 
}

int right(int i)
{ 
	return (i+1)<<1; 
}

struct heap {
	int size;
	int *arr;
};

void buildMaxHeap(struct heap *maxHeap, int i)
{
	int largest = i;
	int l = left(i);
	int r = right(i);

	if(l < maxHeap->size && maxHeap->arr[l] > maxHeap->arr[largest])
		largest = l;
	else 
		largest = i;
	if(r < maxHeap->size && maxHeap->arr[r] > maxHeap->arr[largest])
		largest = r;
	if(largest != i)
	{
		int temp = maxHeap->arr[largest];
		maxHeap->arr[largest] = maxHeap->arr[i];
		maxHeap->arr[i] = temp;
		buildMaxHeap(maxHeap, largest);
	}	
}

struct heap *createAndBuildHeap(int *arr, int size)
{
	int i;
	struct heap *maxHeap = (struct heap *)malloc(sizeof(struct heap));
	maxHeap->size = size;
	maxHeap->arr = arr;
	for(int i = (maxHeap->size - 2)/2; i >= 0; --i)
	{
		buildMaxHeap(maxHeap, i);
	}
	return maxHeap;
}

void heapSort(int *arr, int size)
{
	struct heap *maxHeap = (struct heap *)malloc(sizeof(struct heap));
	maxHeap->size = size;
	maxHeap->arr = arr;

	while(maxHeap->size > 1)
	{
		int temp = maxHeap->arr[0];
		maxHeap->arr[0] = maxHeap->arr[maxHeap->size - 1];
		maxHeap->arr[maxHeap->size - 1] = temp;
		buildMaxHeap(maxHeap, 0);
	}
}

void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
 
/* Driver program to test above functions */
int main()
{ _
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, size);
 
    heapSort(arr, size);
 
    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}