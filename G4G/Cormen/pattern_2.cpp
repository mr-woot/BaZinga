#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

void solve(int l, int c)
{	
	for(int row = 1; row <= l; row++)
	{
		for(int col = 1; col <= c; col++)
		{
			if(row == 1 || row == l) cout << "*";
			else if(col != 1 && col != c) cout << ".";
			else cout << "*";				
		}
		cout << endl;
	}
}

int main()
{ _
	int t;
	cin >> t;
	while(t--)
	{
		int l, c;
		cin >> l >> c;
		solve(l, c);
	}
	return 0;
}