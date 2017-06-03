#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<stack>
#include<iterator>
#include<queue>
using namespace std;

class Graph{
    int v, e;
    vector<list<int> > graph;
public:
    Graph(int, int);
    void createGraph();
    void print();
    //void BFS(int);
    //void DFS(int);
    void topologicalSort();
};

Graph::Graph(int a, int b){
    v = a;
    e = b;
    graph.resize(v);
}

void Graph::createGraph(){
    int v1, v2;
    //char ch1, ch2;
    for(int i=0; i<e; i++){
        cout << "V1---V2: ";
        cin >> v1 >> v2;
        //ch1 = 65+v1; ch2 = 65+v2;
        graph[v1].push_back(v2);
        //graph[v2].push_back(make_pair(v1, ch1));
    }
    print();
}

void Graph::print(){
    for(int i=0; i<v; i++){
        char ch = i+65;
        cout << ch << "->";
        for(list<int>::iterator it=graph[i].begin(); it!=graph[i].end(); ++it){
            char ch1 = *it+65;
            cout << ch1 << " ";
        }
        cout << endl;
    }
}

void Graph::topologicalSort(){
    stack<int> s;
    stack<int> temp;
    set<int> vis;

    for(int i=0; i<v; i++){
        if(vis.find(i)!=vis.end()){ // present in visited
            continue;
        }
        vis.insert(i);
        int start = i;
        while(true){
            for(list<int>::iterator it=graph[start].begin(); it!=graph[start].end(); it++){
                if(vis.find(*it)==vis.end()){ // absent in visited
                    temp.push(start); // cout << "1temp top: " << char(temp.top()+65) << endl;
                    vis.insert(*it);
                    start = *it;
                    it = graph[start].begin();
                    it--;
                    continue;
                }
            }
            s.push(start); // cout << "s top: " << char(s.top()+65) << endl;
            if(temp.empty())
                break;
            start = temp.top(); // cout << "2temp top: " << char(start+65) << endl;
            temp.pop();
        }
    }
    while(!s.empty()){
        char ch = s.top()+65;
        cout << ch << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    int v, e, start;
    cout << "vertices and edges: "; cin >> v >> e;
    Graph g(v, e);
    g.createGraph();
    g.topologicalSort();
    return 0;
}

