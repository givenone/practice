#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void do_something(float t, ofstream &out)
{
    POINT p;
    int cnt = 1;
    char temp[1000];
    //ofstream out = ofstream(argv[1]);

    while(1)
    {
        if (GetCursorPos(&p))
        {
            sprintf(temp, "%d, %d, %d", cnt++, p.x, p.y);
            out << temp << endl;
        }
        //cout << temp;        
        Sleep(t * 1000);
    }
    std::cout << "I am doing something" << std::endl;
}

int main(int argc, char** argv)
{
    float time = atof(argv[2]);
    string path = string(argv[1]);
    path = path + ".csv";
    ofstream out(path);

    do_something(time, out);

}
