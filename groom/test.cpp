#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string ans = "";

    if(n >= 3 && n%2 == 1) {
        ans = "7";
        n-=3;
    }
    for(int i=0; i<n/2; i++)
    {
        ans = ans + "1";
    }

    cout << ans;
}