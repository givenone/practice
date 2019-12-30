#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    char temp[512];
    sprintf(temp, "g++ -o a %s", argv[1]);
    cout << temp;
    system(temp);

    sprintf(temp, "./a < %s > output.txt", argv[2]);
    
    system(temp);
 
    int correct = 0, total = 0;
    string line; 
    string outline;
    string answer;

    ifstream infile("output.txt");
    ifstream ansfile(argv[3]);

    while (getline(infile, line) && getline(ansfile, answer))
    {
        cout << "\r";
        total++;
        if(!line.compare(answer)) correct++;
        else printf("WRONG!!\nExpected : %s\nYour Answer : %s\n", answer.c_str(), line.c_str());
        printf("%d / %d = %d", correct, total, (int)(100 * (float)correct / (float)total));
    }
}