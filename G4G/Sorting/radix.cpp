#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

int getMax(int a[], int n)
{
	int max = a[0];
	for(int i=1; i<n; i++)
	{
		if(max < a[i])
			max = a[i];
	}

	return max;
}

void countSort(int a[], int n, int t)
{
	int out[n];
	int i, count[10] = {0};
	for(i=0; i<n; i++)
		count[(a[i]/t)%10]++;
	
	for(i=1; i<10; i++)
		count[i] = count[i] + count[i-1];

	for(i=n-1; i>0; i--)
	{
		out[count[(a[i]/t)%10] - 1] = a[i];
		count[(a[i]/t)%10]--;
	}

	for(i=0; i<n; i++)
		a[i] = out[i];

}

void radixSort(int a[], int n)
{
	int m = getMax(a, n);
	for(int i=1; m/i > 0; i*=10)
		countSort(a, n, i);
}

int main()
{ _
	int a[] = {12, 342, 170, 4, 78};
	radixSort(a, 5);
	for(int i=0; i<5; i++)
		cout << a[i] << " ";
	return 0;
}