#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pa;
pa po[300000];
vector<int> graph [300000];
bool visited[300000];
int N, M;

int Mx, My, mx, my;

void dfs(int a)
{
    visited[a] = true;
    int x = po[a].first;
    int y = po[a].second;

    if(Mx < x) Mx = x;
    if(My < y) My = y;
    if(mx > x) mx  = x;
    if(my > y) my = y;

    for(int i=0; i<graph[a].size(); i++)
    {
        if(!visited[graph[a][i]])
        {
            dfs(graph[a][i]);
        }
    }
}

int main()
{
    cin >> N >> M;
    int a,b;
    int circum = 0;
    for(int i=0; i<N; i++)
    {
        scanf("%d %d", &a, &b);
        po[i] = pa(a,b);
    }
    for(int i=0; i<M; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    for(int i=0; i<N; i++)
    {
        if(!visited[i])
        {
            Mx = 0; My = 0; mx = 100000000; my = 100000000;
            dfs(i);
            circum = max(circum, ((Mx - mx) + (My - my)) * 2);
        }
    }

    cout << circum << endl;
}