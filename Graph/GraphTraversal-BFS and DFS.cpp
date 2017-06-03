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
    void BFS(int);
    void DFS(int);
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

void Graph::BFS(int start){
    queue<int> q;
    set<int> s;
    q.push(start);
    while(!q.empty()){
        s.insert(start);
        for(list<int>::iterator it=graph[start].begin(); it!=graph[start].end(); it++){
            if(s.find(*it)==s.end()){
                q.push(*it);
                s.insert(*it);
            }
        }
        cout << start << " ";
        q.pop();
        start = q.front();
    }
    cout << endl;
}

void Graph::DFS(int start){
    stack<int> s;
    set<int> vis;
    s.push(start);
    vis.insert(start);
    while(!s.empty()){
        start = s.top();
        cout << start << " ";
        s.pop();
        for(list<int>::iterator it=graph[start].begin(); it!=graph[start].end(); it++){
            if(vis.find(*it)==vis.end()){
                s.push(*it);
                vis.insert(*it);
            }
        }
    }
    cout << endl;
    /*cout << "dfs\n";
    stack<int> s;
    set<int> visited;
    s.push(start);
    visited.insert(start);
    cout << start << " ";
    list<int>::iterator it = graph[start].begin();
    while(!s.empty()){
        start = s.top();
        for(list<int>::iterator it=graph[start].begin(); it!=graph[start].end(); it++){
            if(visited.find(*it)==visited.end()){
                start = *it;
                cout << start << " ";
                s.push(start);
                visited.insert(start);
                it = graph[start].begin();
                it--;
                continue;
            }
        }
        s.pop();
    }
    cout << endl;*/
}

int main(){
    int v, e, start;
    cout << "vertices and edges: "; cin >> v >> e;
    Graph g(v, e);
    g.createGraph();
    cout << "BFS start vertex: "; cin >> start;
    g.BFS(start);
    cout << "DFS start vertex: "; cin >> start;
    g.DFS(start);
    return 0;
}
