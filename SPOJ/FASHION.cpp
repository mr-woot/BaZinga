#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        
        int a[n];
        int b[n];
        long long sum=0;

        for(int i=0; i<n; i++)   
            scanf("%d", &a[i]);
        sort(a, a+n);
        for(int j=0; j<n; j++)
            scanf("%d", &b[j]);
        sort(b, b+n);
        for(int i = 0; i < n; i++){
            sum += (long long)a[i]*b[i];
        }
        cout << sum <<endl;
    }
    return 0;
}