#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

double pow(int a, int b)
{
    if(b == 0) return 1;
    if(b == 1) return a;

    double t = pow(a, b/2);

    return t * t * pow(a, b%2);
}

int main()
{ _
    int a, b, c;

    do{
        cin >> a >> b >> c;
        if(a == 0)
            if(b == 0)
                if(c == 0)
                    break;
        if(2 * b == (a + c))
            cout << "AP " << 2*c - b << endl;
        else
            cout << "GP " << (double)(a) * pow(b/a, 3) << endl;
    }while(1);

	return 0;
}