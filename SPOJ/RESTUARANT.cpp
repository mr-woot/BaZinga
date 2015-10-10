#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--) {
        int l, b;
        cin >> l >> b;
        if(l == b) cout << l << endl;
        else{
            int i=1;
            int max = i;
            int ans = max;
            while(i++) {
                if(i*i > l*b) 
                    break;
                
                if((l*b)%(i*i) == 0)
                    max = (l*b)/(i*i);
                
                if(ans < max) ans = max;
            }
            cout << ans << endl;
        }
    }
    return 0;
}