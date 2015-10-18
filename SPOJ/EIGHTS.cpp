#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef unsigned long long ull;

int main() 
{ _
	
	int t;
	cin >> t;
	while(t--) {
		ull n;
		cin >> n;
		cout << (192 + (n-1)*250) << endl; 
	}

	return 0;
}