#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
    	string s1, s2;
    	cin >> s1;
    	int i=0;
    	while(s1[i++]) {
            if(!(s1[i] == s1[i+1]))
                s2[i]=s1[i];
        }
        
    	cout << s2 << endl;
    }
    return 0; 
}
