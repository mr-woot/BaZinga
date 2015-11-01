#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define MOD 100000010LL

using namespace std;

typedef long long int ll;

int getLength(ll val)
{
	int count=0;

	while(val!=0)
	{
		count++;
		val/=10;
	}

	return count;
}

ll kartsuba(ll x, ll y)
{
	int xLen = getLength(x);
	int yLen = getLength(y);

	int N = (int)fmax(xLen, yLen);

	if(N<10) return x*y;

	N = (N/2) + (N%2);

	ll a, b, c, d, z0, z1, z2, mul;

	mul = pow(10, N);
	b = x/mul;
	a = x - (b*mul);
	d = y/mul;
	c = y - (d*N);

	z0 = kartsuba(a, c);
	z1 = kartsuba(a+b, c+d);
	z2 = kartsuba(b, d);

	return z0 + ((z1-z0-z2) * mul) + (z2 * (ll)pow(10, 2*N));
}

int main()
{ _
	int t;
	scanf("%d", &t);
	while(t--) {
		ll a, b, result;
		scanf("%lld %lld", &a, &b);
		result = kartsuba(a, b);
		printf("%lld\n", result);
	}
	return 0;
}