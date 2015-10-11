#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;


long long int dp[10005];
long long int arr[10005];
int n;

long long f(int i) {
	if(i>=n) return 0;
	if(i == n-1) return arr[i];

	if(dp[i] != 0) return dp[i];
	
	dp[i] = max(arr[i] + f(i+2), f(i+1));

	return dp[i];
}

int main()
{ _
	int t;
	cin >> t;
	for(int j=1; j<t+1; j++) {
		cin >> n;
		for(int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);
		printf("Case %d: %lld\n",j,f(0));
	}

	return 0;
}