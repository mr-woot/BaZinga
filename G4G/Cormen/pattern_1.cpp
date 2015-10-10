#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

void solve(int l, int c)
{
	if(c == 1)
	{
		for(int i = 1; i <= l; i++)
		{
			if(i % 2 == 0) cout << "." << endl;
			else cout << "*" << endl;
		}	
		return;
	}
	
	for(int i = 1; i <= l; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			if(i % 2 == 0 && j % 2 == 0) cout << "*";
			else if(i % 2 == 0 && j % 2 != 0) cout << ".";
			else if(i % 2 != 0 && j % 2 == 0) cout << ".";
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