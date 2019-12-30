#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    char temp[512];
    sprintf(temp, "g++ -o a %s", argv[1]);
    system(temp);

    sprintf(temp, "./a < %s > output.txt", argv[2]);
    cout << temp;
    system("./a < i1.in > output.txt");
 
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
        else printf("WRONG!!\n Expected : %s\n Your Answer : %s");
        printf("%d / %d = %d", correct, outline, (int)(100 * (float)correct / (float)total));
    }

}