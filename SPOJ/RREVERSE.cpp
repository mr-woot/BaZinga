#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int lli;

int rreverse(lli n, lli x)
{
	if(n == 0) return x;

	return rreverse(n/10, 10*x + n%10);
}

int main()
{ _
	lli x;
	while(cin >> x)
	{
		lli n = 0;	
		cout << rreverse(x, n) << endl;
	}
	return 0;
}