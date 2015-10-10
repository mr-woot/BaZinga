//................................
//Code Chef October Challenge 2015
//................................
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

bool subinc(int a[], int i, int j)
{
	if(i == j) return true;
	if(i > j) return false;
	if(a[i] > a[j]) return false;

	for (int k = i; k < j ; k++)
	{
		if(a[k+1] < a[k])
			return false;
	}
	return true;
}

int main()
{ _
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int v[n];
		for(int i=0; i<n; i++) {
			cin >> v[i];
		}
		int count=0;
		for(int i=0; i<n; i++) {
			for(int j=i; j<n; j++) {
				if(subinc(v, i, j))
					count++;
			}
		}
		cout << count << endl;
	}
	
	return 0;
}