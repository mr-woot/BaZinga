#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pt(x) printf("%d\n",x)
#define ptl(x) printf("%lld\n",x)
const int mod = 1000000007;
 
 int stoi(string &s)
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int main()
{ _

    int t;
    while(t--){
        string s, s1, s2;
        cin >> s;

        cout << " ";
        int c = 0;

        for(int i = 0; s[i] != '+'; i++)
        	c++;

        s1 = s.substr(0, c);
        s2 = s.substr(c+1, s.length());
        
        cout << s1 << endl << "+" << s2 << endl;

        for(int i = 0; i <= c; i++)
        	cout << "-" ;

        int k = stoi(s1) + stoi(s2);
    
    	cout << k;
    }
    return 0;
}