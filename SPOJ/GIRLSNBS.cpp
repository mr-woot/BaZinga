#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int solve(int g, int b)
{
	if(b == g) return 1;
	else if (b == 0 || g == 0) return b + g;
	else return abs(b - g) - 1;
}

int main()
{ _
	int g, b;
	cin >> b >> g;
	
	while(b != -1 && g != -1);
	{	
		cout << solve(g, b) << endl;
	}
	return 0;
}