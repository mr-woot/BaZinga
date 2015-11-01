#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef unsigned long long int ull;
int min(int a, int b, int c) 
{ 
	if(a<=b && a<=c) return a;
	else if(b<=a && b<=c) return b;
	else return c;
}
int main()
{ _
	int t;
	cin >> t;
	while(t--) {
		char s1[2005], s2[2005];
		scanf("%s", &s1);
		scanf("%s", &s2);
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int dp[2005][2005];

		//memset(dp, 0, sizeof(dp[0][0])*(len1+1)*(len2+1));
		
		for(int i=0; i<=len1; i++)
			dp[i][0] = i;
		for(int i=0; i<=len2; i++)
			dp[0][i] = i;
		for(int i=1; i<=len1; i++)
		{	
			for(int j=1; j<=len2; j++)
			{
				if(s1[i-1] == s2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = dp[i-1][j-1]+1;

				dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1,dp[i][j]);
			}
		}
		cout << dp[len1][len2] << endl;
	}
	return 0;
}