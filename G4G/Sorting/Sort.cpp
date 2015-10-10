#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<float> vf;
typedef vector<int> vi;


void bucketSort(float arr[], int n)
{
	vf b[n];
	
	for(int i=0; i<n; i++)
	{
		int bi = n*arr[i];
		b[bi].push_back(arr[i]);
	}
	
	for(int i=0; i<n; i++)
	{
		sort(b[i].begin(), b[i].end() - 1);
	}
	int index = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<b[i].size(); j++)
		{
			arr[index++] = b[i][j];
		}
	}
}
// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual position of
    // this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to curent digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead of passing digit
    // number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {897, 565, 56, 12, 665, 4};
    float a[] = {0.434, 0.353, 0.979, 0.123, 0.754};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
 
    cout << "Sorted array is(radix) \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";

   cout << endl;
   bucketSort(a, 5);
 
    cout << "Sorted array is(bucket) \n";
    for (int i=0; i<n; i++)
       cout << a[i] << " ";
    return 0;
}