#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() { _
	
	// your code here
	int n, k;
	cin >> n >> k;
	int a[n], count=0;
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(abs(a[i]-a[j]) < k)
				count++;
		}
	}
	cout << count;
	return 0;
}