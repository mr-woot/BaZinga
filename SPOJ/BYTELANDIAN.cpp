#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

map<int, long long> dp;

long long f(int n) {
	if(n==0) return 0;

	if(dp[n] != 0) return dp[n];
	long long aux = f(n/2) + f(n/3) + f(n/4);

	if(aux > n) dp[n] = aux;
	else dp[n] = n;

	return dp[n];
}

int main()
{ _
	int n;
	while(scanf("%d", &n) == 1)
		printf("%lld\n", f(n));
	return 0;
}