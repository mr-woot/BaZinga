#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int areAll9s(string s)
{
	for(int i = 0; i < s.length(); i++)
		if(s[i] != 9) 
			return 0;

	return 1;
}

void generatePalinUtil(string &num)
{
	int n = num.length();
	int mid = num.length()/2;
	cout << n;
	bool leftsmaller = false;

	int i = mid - 1;
	int j = (n % 2) ? mid + 1 : mid;

	while(i >= 0 && num[i] == num[j])
		i--,j++;

	if(i < 0 || num[i] < num[j])
		leftsmaller = true;

	while(i >= 0)
	{
		num[j++] = num[i--];
	}

	if(leftsmaller == true)
	{
		int carry = 1;
        i = mid - 1;
 
        // If there are odd digits, then increment
        // the middle digit and store the carry
        if (n%2 == 1)
        {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
            j = mid;
 
        // Add 1 to the rightmost digit of the left side, propagate the carry 
        // towards MSB digit and simultaneously copying mirror of the left side 
        // to the right side.
        while (i >= 0)
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--]; // copy mirror to right
        }
	}
}

void generatePalin(string &str)
{
	int i;

	if(areAll9s(str))
	{
		cout << '1';
		for(int i = 1; i < str.length(); i++)
			cout << '0';
		cout << '1';
	}
	else
	{
		generatePalinUtil(str);
		cout << str;
	}
}

int main()
{ _
	int t;
	cin >> t;
	while(t--)
	{
		int num;
		cin >> num;
		string s = patch::to_string(num);
		generatePalin(s);
	}
	return 0;
}