#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<iterator>
using namespace std;
class Graph{
private:
    int v, edges;
    int v1, v2;
    vector<list<int> >graph;
public:
    Graph();
};
Graph::Graph(){
    cout << "*** An Undirected Graph ***\n";
    cout << "vertices and edges: ";
    cin >> v >> edges;
    graph.resize(v);
    for(int i=0; i<edges; i++){
        cout << "V1---V2: ";
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i=0; i<v; i++){
        cout << i << ": ";
        for(list<int>::iterator it=graph[i].begin(); it!=graph[i].end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "\nRemove..\n";

    while(true){
        cout << "V1---V2: ";
        cin >> v1 >> v2;

        graph[v1].remove(v2);
        graph[v2].remove(v1);

        for(int i=0; i<v; i++){
            cout << i << ": ";
            for(list<int>::iterator it=graph[i].begin(); it!=graph[i].end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    Graph g;
    return 0;
}
