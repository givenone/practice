#include <bits/stdc++.h>

using namespace std;
class A
{
    public :
    string a, b, c;

    A(string x, string y, string z)
    {
        a = x; b = y; c = z;
    }
};

int main()
{
    A *temp ;
    map <string, A*> graph;
    while(1){
    string x = "123";
    temp = new A(x, x, x);
    graph["11"] = temp;
    cout << graph["11"]->a << graph["11"]-> b << graph["11"] -> c << endl; 

    cout << temp->a << temp-> b << temp -> c << endl; 
    break;
    }
    cout << graph["11"]->a << graph["11"]-> b << graph["11"] -> c << endl; 

    cout << temp->a << temp-> b << temp -> c << endl; 
}