#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define MOD 109546051211LL

using namespace std;

long long int fact[10000001];
long long int factm[10000001];

long long int mulmod(long long int a, long long int b)
{
	long long int res = 0;
	while(b) 
	{
		if(b%2)
		{
			res+=a;
			if(res>=MOD)
				res-=MOD;
		}
		b/=2;
		a=a*2;
		if(a>=MOD)
			a-=MOD;
	}
	return res;
}

long long int factmul(long long int n)
{
	fact[0] = factm[0] = 1;

	for(int i=1; i<=n; i++)
	{
		fact[i]  = mulmod(i, fact[i-1]) % MOD;
		factm[i] = mulmod(factm[i-1],fact[i]) % MOD;
	}

	return factm[n] % MOD;
}

int main()
{ _
	long long int n, result;
	scanf("%lld", &n);
	
	if(n>=587117)
		printf("0\n");
	else
	{
		result = factmul(n);
		printf("%lld\n", result);
	}
	
	return 0;
}