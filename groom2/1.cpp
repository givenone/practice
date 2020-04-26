#include <bits/stdc++.h>

using namespace std;

long long ans[100000];
long long del[100000];
int N;
long long mx = -1000000;
int main()
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> del[i];
        mx = max(mx, del[i]);
        ans[i] = del[i];
    }
    
    for(int k=2; k<=N; k++)
    {
        for(int i=0; i<N; i++)
        {
            if(i+k-1 >= N) break;
            ans[i] = ans[i] + del[i+k-1];
            mx = max(mx, ans[i]);
        }
    }

    cout << mx << endl;
    


}