#include<iostream>

using namespace std;

int tile[50][50];
int M, N;

bool check(int i, int j)
{
    if(i >= 0 && i < M && j >= 0 && j < N && tile[i][j] != 0) return true;
    else return false;
}

bool check1(int i, int j)
{
    bool t1 = check(i-1, j-1);
    bool t2 = check(i-1, j);
    bool t3 = check(i-1, j+1);
    bool t4 = check(i, j-1);
    bool t5 = check(i, j+1);
    bool t6 = check(i+1, j-1);
    bool t7 = check(i+1, j);
    bool t8 = check(i+1, j+1);

    if(t1 && t2 && t4) 
    {
        //tile[i-1][j-1] = 2;
        //tile[i-1][j] = 2;
        //tile[i][j-1] = 2;
        return true;
    }
    if(t5 && t2 && t3)
    {
        //tile[i][j+1] = 2;
        //tile[i-1][j] = 2;
        //tile[i][j-1] = 2;
        return true;
    }
    if(t4 && t6 && t7)
    {
        //tile[i][j-1] = 2;
        //tile[i+1][j-1] = 2;
        //tile[i+1][j] = 2;
        return true;
    }
    if(t5 && t7 && t8)
    {
        //tile[i][j+1] = 2;
        //tile[i+1][j] = 2;
        //tile[i+1][j+1] = 2;
        return true;
    } 

    return false;
}

int main()
{
    int NUM;
    cin >> NUM;

    for(int test = 1; test <= NUM ; test++)
    {
        cin >> M >> N;
        int cnt = 0;
        for(int i = 0; i < M; i ++)
        {
            for(int j = 0 ; j<N; j++)
            {
                cin >> tile[i][j];
                if(tile[i][j]) cnt++;
            }
        }

        for(int i = 0; i < M; i ++)
        {
            for(int j = 0 ; j<N; j++)
            {
                if(tile[i][j] == 1)
                {
                    if(check1(i, j)){ cnt--;}
                }
            }
        }
        if(cnt == 0) cout << "YES" << endl;
        else cout <<"NO" <<endl;
    }

}