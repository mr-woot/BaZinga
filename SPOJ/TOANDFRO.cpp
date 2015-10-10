#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

void solve(string &str, int size)
{
	char mat[size][size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; i++)
		{
			mat[i][j] = 'x';
		}
	}
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
}

int main()
{ _
	int matSize;
	while(cin >> matSize)
	{
		string s;
		cin >> s;
		solve(s, matSize);
	}

	return 0;
}