#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pa;
typedef pair<pa, int> tri;
vector<int> endtime;
int N;
tri t[100000];
int ans[100000];

int main()
{
    cin >> N;
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d %d", &a, &b);
        t[i] = tri(pa(a,b), i);
    }
    sort(t, t+N);

    
    for(int i = 0; i<N ; i++)
    {
        int idx = t[i].second;
        int s = t[i].first.first;
        int e = t[i].first.second;
        //length = i; find index of first 
        int left = 0, right = i;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(endtime[mid] <= s)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        ans[idx] = i - left;
        endtime.push_back(e);
        sort(endtime, endtime + (i + 1));
        // add ei to list;

    }

    for(int i=0; i<N; i++) cout << endtime[i] << endl;

}