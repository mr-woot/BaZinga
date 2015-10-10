//................................
//Code Chef October Challenge 2015
//................................
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{ _
	int t;
	cin >> t;
	while(t--) {
		int n; //no. of questions
		cin >> n;

		char knows[n];
		scanf("%s", knows);

		char correct[n];
		scanf("%s", correct);

		int w[n];
		for(int i=0; i<=n; i++)
			scanf("%d", &w[i]);

		int count=0;

		for(int i=0; i<n; i++)
			if(knows[i] == correct[i])
				count++;
		printf("%d\n", w[count]);	
	}

	return 0;
}