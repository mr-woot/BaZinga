#include<stdio.h>

int bSearch(int a[], int l, int r, int key)
{
	if(l <= r)
	{
		int mid = l + (r - 1)/2;

		if(a[mid] == key) return mid + 1;

		else if (a[mid] < key) return bSearch(a, l, mid - 1, key);

		else return bSearch(a, mid + 1, r, key);
	}

	return -1;
}

void iSort(int a[], int n)
{
	if(n > 1)
	{
		iSort(a, n-1);
		int key = a[n];
		int i = n-1;

		while(i >= 0 && a[i] > key)
		{
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}

void printArray(int a[], int n)
{
	int i = 1;
	while(i <= n)
		printf("%d  ", a[i++]);
}

int main()
{
	int a[] = {0, 32, 48, 54, 19, 21, 67, 89};
	//int key = bSearch(a, 0, 9, 32);
	//int i = 0;
	//printf("%d", key);
	iSort(a, 7);
	printArray(a, 7);

	return 0;
}