#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int sieveN(int n)
{
	int boolean[n-1];
	int list[n-1];
	int ctr, outctr, inctr, primeassm;

	for (ctr = 0; ctr < n-1; ctr++)
	{
		list[ctr] = ctr+2;
		boolean[ctr] = 1;
	}

	for(outctr = 0; outctr < n/2+1; outctr++)
	{
		if(boolean[outctr] == 1)
		{
			primeassm = list[outctr];
			for(inctr = outctr+1; inctr < n-1; inctr++)
			{
				if(list[inctr]%primeassm == 0)
					boolean[inctr] = 0;
			}
		}
	}
	int i;
	for (i = 0; i < n-1; i++);
		return list[i];
	
}

int main()
{ _
	int n;
	scanf("%d", &n);
	cout << sieveN(n);
	return 0;
}




