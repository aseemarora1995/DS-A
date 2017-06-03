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
    void DFS(int);
    bool DFSUtil(int, set<int> &, int);
};

Graph::Graph(int a, int b){
    v = a;
    e = b;
    graph.resize(v);
}

void Graph::createGraph(){
    int v1, v2;
    for(int i=0; i<e; i++){
        cout << "V1---V2: ";
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    print();
}

void Graph::print(){
    for(int i=0; i<v; i++){
        cout << i << "->";
        for(list<int>::iterator it=graph[i].begin(); it!=graph[i].end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
}

bool Graph::DFSUtil(int start, set<int> &vis, int parent){
    // cout << "start: " << start << " parent: " << parent << endl;
    for(list<int>::iterator it=graph[start].begin(); it!=graph[start].end(); it++){
        if(*it==parent)
            continue;
        if(vis.find(*it)!=vis.end()){
            return false;
        }
        vis.insert(*it);
        return DFSUtil(*it, vis, start);
    }
    return true;
}

void Graph::DFS(int start){
    stack<int> s;
    set<int> vis;
    if(DFSUtil(start, vis, -1))
        cout << "no cycle\n";
    else cout << "cycle exists\n";
}

int main(){
    int v, e, start;
    cout << "vertices and edges: "; cin >> v >> e;
    Graph g(v, e);
    g.createGraph();
    //cout << "BFS start vertex: "; cin >> start;
    //g.BFS(start);
    cout << "DFS start vertex: "; cin >> start;
    g.DFS(start);
    return 0;
}
