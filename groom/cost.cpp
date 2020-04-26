#include<iostream>
#include<algorithm>

using namespace std;
int interval[3000];
int num[3000];
int main()
{
    int N, K;
    
    cin >> N >> K;

    for(int i=0; i<N;i++) cin >> num[i];

    for(int i=0; i<N-1;i++) interval[i] = num[i+1]-num[i];

    sort(interval, interval + N-1); // 0 ~ N-2 (N-1개)

    int sum = 0;
    for(int i=1; i <= K-1; i++) sum += interval[N-i-1];

    cout << (num[N-1]-num[0] - sum) << endl;


}