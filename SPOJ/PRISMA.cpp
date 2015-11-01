#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define pi 3.14159265

using namespace std;
typedef unsigned long long ull; 
int main()
{ _
	int t;
	scanf("%d", &t);
	while(t--) {
		ull v;
		cin >> v;
		double S, s1, a, s2, h;

		a = (double)cbrt(4*v);
		h = (double)a/sqrt(3);

		s1 = (double)((double)pow(a,2) * (double)sqrt(3)/2);
		s2 = (double)3*a*h;
		S = s1+s2;
		
		printf("%f\n", S);
	}
	return 0;
}