#include<bits/stdc++.h>

using namespace std;

int B[10001];

multiset<int> Elsie;
multiset<int> Bessie;
int main()
{
    int N, K;
    
    ifstream in("berries.in"); ofstream out("berries.out");
    in >> N >> K;

    for(int i=0; i<N; i++) in >> B[i];

    sort(B, B+N);

    for(int i= 0; i < K/2 ; i++) Elsie.insert(B[N-i-1]);
    for(int i= K/2; i< K ; i++) Bessie.insert(B[N-i-1]);

    int BMax, EMax, BMin, EMin;


    while(true)
    {
            multiset<int>::iterator temp;
    //int sum = 0;
    //for(temp = Bessie.begin(); temp != Bessie.end(); ++temp) cout <<  *temp << ' ';
    //cout << endl;
        BMax = *Bessie.rbegin();
        BMin = *Bessie.begin();
        EMax = *Elsie.rbegin();
        EMin = *Elsie.begin();
       // printf("%d %d %d %d\n",BMax, BMin, EMax, EMin);
        if(BMin + BMax >= EMax) break;
        int xx = (EMax - BMax > EMax / 2) ? EMax/2 : EMax - BMax;
        int yy = EMax - xx;

        Bessie.erase(BMin);
        Bessie.insert(xx);

        Elsie.erase(EMax);
        Elsie.insert(yy);
    }
    
    multiset<int>::iterator temp;
    int sum = 0;
    for(temp = Bessie.begin(); temp != Bessie.end(); ++temp) sum += *temp;

    out << sum << endl;

}