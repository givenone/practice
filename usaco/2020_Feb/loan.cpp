#include<bits/stdc++.h>

using namespace std;

long long N, K, M;

bool check(long long X){
    long long G = 0;
    long long Y = (N - G) / X;
    long long cnt = 0;
    long long n = log(N) / log(M*X); //cout << n;
    long long GG = N *(1.0 - pow(1.0 - 1.0/(double)X, n)); 
    if(K > n + ( N-GG ) / M ) return true;
    while(Y >= M)
    {
        if(cnt > K) return false;
        
        G += Y;
        Y = (N-G) / X;
        cnt ++;
    }
    //cout << cnt << endl;
    cnt += (N-G + M - 1) / M;

    //cout <<  n +  ( N-GG + M -1) / M << ' ' << cnt << endl;
    return K >= cnt;
}
int main()
{
    ifstream in("loan.in"); ofstream out("loan.out");
    in >> N >> K >> M;


    long long left = 1;
    long long right = N;

    while (left < right)
    {
        long long mid = (left + right + 1) / 2;

        if(check(mid)) left = mid;
        else right = mid-1;
    }

    out << left << endl;
}