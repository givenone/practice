#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pa;

vector <pa> graph[100001];
int N, M;
int where[100001];
bool visited[100001];
int weight[100000];

bool dfs(int i, int th)
{
    if(where[i] == i) return true;
    visited[i] = true;
    for(int j=0; j<graph[i].size();j++) 
    {
        int next = graph[i][j].first;
        if(!visited[next] && graph[i][j].second >= th){
            int temp = where[i];
            where[i] = where[next];
            where[next] = temp;
            if(dfs(next, th)) return true;
            else{
                int temp = where[i];
                where[i] = where[next];
                where[next] = temp;
            }
        }
    }
    return false;
}
int main()
{
    ifstream in("wormsort.in"); ofstream out("wormsort.out");
    cin >> N >> M;
    bool flag = false;
    for(int i=1; i<=N; i++) 
    {
        cin >> where[i];
        if(where[i] != i) flag = true;
    }
    if(!flag) {
        cout << -1 << endl;
        return 0;
    }
    for(int i=1; i<=M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        weight[i-1] = w;
        graph[a].push_back(pa(b,w));
        graph[b].push_back(pa(a,w));
    }

    sort(weight, weight + M);

    int left = 0, right = M-1;

    while(left < right)
    {
        int mid = (left + right+1) / 2;
        for(int j=1; j<=N; j++){
            for(int i=1; i<=N; i++)
            {
                visited[i] = true;
            }
            if(!dfs(j, weight[mid])) {
                left = mid;
                break;
            }
        }
        right = mid - 1;
    }

    cout << weight[left] << endl;



}