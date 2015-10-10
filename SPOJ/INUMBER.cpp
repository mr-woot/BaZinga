#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() { _
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int i = n;
		int d;
		while(i)
		{
			d = (n/i);
			if((1 + (n - 1)%9)==n)
				break;
			i = i + n;
		}
		cout << d;
	}
	return 0;
}