#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{ _
	int n;
	int ep;
	int sum=0;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> ep;
		sum+=ep;
	}
	int total = n*(n+1);
	cout << (total/2) - sum;
	return 0;
}