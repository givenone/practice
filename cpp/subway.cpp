  
#include <bits/stdc++.h>

using namespace std;

class Vertex;

typedef pair<Vertex*, int> edge;

class Vertex{
public:
    string name, id, line;
    vector<edge> edgelist;

    Vertex(){
        name = "없음";
        id = "없음";
        line = "없음";
    }

    Vertex(string a, string b, string c){
        name = a;
        id = b;
        line = c;
    }

};


int main(){

    ifstream data("data_1.txt");    
    string line;
    map<string, Vertex *> graph_id;
    map<string, Vertex *> graph_name;
    while(getline(data,line) )
    {
        cout << line << endl;

        string a, b, c;

        istringstream ss(line);
        ss >> a >> b >> c;
        Vertex *temp = new Vertex(b, a, c);

        graph_id[a] = temp;
        graph_name[b] = temp;
        cout << temp->name  << ' ' <<temp->id  << ' ' <<temp->line <<endl;
        
    } 
    cout << graph_id["133"]->id;

    //while // edge
    //while (/* condition */)
    {
        /* code */
    }
    


    
    data.close();

    // dijkstra


}