#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

int optimalCoinChange(int a[], int n, int sum)
{
	int dp[sum+1];
	dp[0] = 0;
	for(int i=1; i<=sum; i++)
		dp[i] = INT_MAX;
	for(int i=1; i<=sum; i++)
		for(int j=0; j<n; j++)
			if(a[j] <= i)
			{
				int sub_res = dp[i-a[j]];
				if(sub_res != INT_MAX && sub_res+1 < dp[i])
					dp[i] = sub_res+1;
			}

	return dp[sum];		
}
int min(int a, int b){ return a<b?a:b;}
int coin(int a[], int n, int t)
{
	int dp[n+1][t+1];
	for(int i=0; i<n; i++)
	{
		for (int j = 0; j <= t; j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
			if(i==1) 
				dp[i][j] = j;
			else if(a[i-1]>j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = min((dp[i][j-a[i-1]]+1), dp[i-1][j]);
		}
	}
	return dp[n][t];
}

int main()
{ _
	int n;
	cin >> n;
	int val[n];
	for(int i=0; i<n; i++) 
		scanf("%d", &val[i]);
	cout << "Enter the total sum: " << endl;
	int sum;
	cin >> sum;
	cout << coin(val, n, sum);
	return 0;
}