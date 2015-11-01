#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef unsigned long long int ull;

int main()
{ _
	int t;
	cin >> t;
	while(t--) {
		char s[1000];
		scanf("%s", &s);
		ull len = strlen(s);
		ull dp[len];
		memset(dp, 0, sizeof(dp));
		dp[0]=1;
		ull x;
		for(ull i=1; i<len; i++)
		{
			x=(s[i-1]-'0')*10 + (s[i]-'0');
			if(s[i]-'0') 
				dp[i] = dp[i-1]; 
			if(x>=10 && x<=26)
				dp[i] = dp[i] + dp[(i-2)<0?0:i-2];
		}
		//printf("%llu\n", dp[len-1]);
		cout << dp[len-1];
	}
	return 0;
}