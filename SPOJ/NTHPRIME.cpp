#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
#define limit 1000000001
#define SIZE 23000000000
using namespace std;
typedef unsigned long long ull;
typedef vector<ull> vll;

void scanint(ull &x)
{
    register ull c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void sieveNth(ull n)
{
	vector<bool> bools(numeric_limits<ull>::max() + 1);
	
	bools[0] = bools[1] = false;
	for(int i = 2; i < SIZE + 1; i++)
		bools[i] = true;

	for (int p = 2; p < sqrt(SIZE); p++)
	{
		if(bools[p])
		{
			for(int i = p*p; i < SIZE; i+=2)
				bools[p] = false;
		}
	}
	ull x = 0;
	ull count = 0;
	while(count <=n)
	{	
		if(bools[x]) 
			count++;
		x++;
	}
	pc(--x);
}

int main()
{ _
	ull n;
	scanint(n);
	sieveNth(n);
	return 0;
}