#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lsearch(int a[], int n, int key) {
    for(int i=0; i<n; i++)
        if(a[i] == key)
            return i;
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin >> t;
    while(t--) {
        int n, key,i;
        cin >> n >> key;
        
        int a[n];
        for(int j=n-1, i=0; i<n; i+=2, j--)
            a[i] = j;
        for(int j=0, i=1; i<n; i+=2, j++)
            a[i] = j;
        int ans = lsearch(a, n, key);
        cout << ans << endl;
    }
    return 0;
}
