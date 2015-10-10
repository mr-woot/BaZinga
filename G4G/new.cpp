#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int isPrime(int n)
{
	for(int i = 2; i <= sqrt(n); ++i)
	{
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}

int nextPrime(int n)
{
	int p = n+1;
	while(p)
	{
		if(isPrime(p))
			break;
		p++;
	}
	return p;
}

int main()
{ _
	int n;
	int i = 0;
	int prime = 1;
	scanf("%d", &n);

	while(i++ < n){
		prime = nextPrime(prime);
	}
	cout << prime;
	return 0;
}