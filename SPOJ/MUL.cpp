#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
int main()
{ _
	int t;
	cin >> t;
	while(t--)
	{
		int N1, N2;
		cin >> N1 >> N2;
		int a[200], m=0, i=0, flag=N1;
		while(flag!=0)
		{
			a[i++] = flag%10;
			flag/=10;
			m++;
		}
		int temp, x=0, index=0;
		temp=0;
		for(index=0; index<m; index++)
		{
			x = a[index]*N2 + temp;
			a[index] = x%10;
			temp = x/10;
		}
		while(temp!=0)
		{
			a[index++] = temp%10;
			temp = temp/10;
			m++;
		} 
		for(i=m-1; i>=0; i--)
			cout << a[i];
	}
	return 0;
}