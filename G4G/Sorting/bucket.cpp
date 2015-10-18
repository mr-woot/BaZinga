#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

void bucket(float a[], int n)
{
    vector<float> b[n];
    for(int i=0; i<n; i++)
    {
        int bi = n*a[i];
        b[bi].push_back(a[i]);
    }

    for(int i=0; i<n; i++)
        sort(b[i].begin(), b[i].end());

    int index = 0;

    for(int i = 0; i<n; i++)
        for(int j=0; j<b[i].size(); j++)
            a[index++] = b[i][j];
} 
 
int main()
{ _
    float arr[] = {0.10, 0.4215, 0.7510, 0.9030, 0.8022, 0.264, 0.27, 0.669};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucket(arr, n);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}