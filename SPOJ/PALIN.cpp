#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef unsigned long long ull;
//template<class Int_Type>
ull NextPalindromeNumber(ull number)
{
    std::stringstream ss;
    std::string numberString;
    do
    {
        number++;
        ss.clear();
        ss.str("");
        ss << number;
        ss >> numberString;
    }
    while(!equal(numberString.begin(), numberString.begin()+numberString.size()/2, numberString.rbegin()));
    return number;
}
int main() 
{ _
    int c;
    cin >> c;
    while(c--) 
    {
        ull n;
        cin >> n;
        cout << NextPalindromeNumber(n) << endl;
    }
    return 0;
}