#include<bits/stdc++.h>
#define MAX 100000000
#define LIM 1010
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
unsigned flag[MAX>>6]={0};
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x)
#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))         //LINE 1
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))        //LINE 2
/*void scanint(ull &x)
{
    register ull c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
*/
using namespace std;
void sieve(long n) 
{
    int i, j, k;
    //int *v = new int[MAX + 1];
    
    //for(int j = 0; j < LIM; j++) v[i] = 1;
    
    for(i=3; i<LIM; i+=2)
    {	
        if(!ifc(i))
        {
        	cout << i << endl;
        	for(j=i*i, k=i<<1; j<LIM*LIM; j+=k)
            {
                isc(j);
            }
        }
    }
    /*
    int count = 0, x = 0;
    while(count < n)
    {
    	if(v[x])
    	{
    		count++;
    	}
    	x++;
    }
    x--;
    cout << x;
	*/
}
int main()
{ _
	sieve(1000);
	return 0;
}