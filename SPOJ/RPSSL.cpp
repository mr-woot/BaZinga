//..............
//SPOJ-RPSLS.cpp
//..............
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{ _
	int t;
	cin >> t;
	while(t--) {
		int Rr, Rp, Rsc, Rl, Rsp;
		int Sr, Sp, Ssc, Sl, Ssp;
		scanf("%d%d%d%d%d", &Rr, &Rp, &Rsc, &Rl, &Rsp);
		scanf("%d%d%d%d%d", &Sr, &Sp, &Ssc, &Sl, &Ssp);
		double w, l, d, P;
		w = Rr*(Sl+Ssc) + Rsc*(Sp+Sl) + Rp*(Sr+Ssp) + Rl*(Ssp+Sp) + Rsp*(Sr+Ssc);
		d = (Rr*Sr) + (Rp*Sp) + (Rsc*Ssc) + (Rl*Sl) + (Rsp*Ssp);
		w/=10000;
		d/=10000;
		l = 1-d-w;
		P = ((w*w)/pow((1-d), 2)) + ((2*l*w*w)/pow((1-d), 3));
		printf("%d\n", (int)P*10000);
	}

	return 0;
}