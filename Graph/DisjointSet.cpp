#include<iostream>
#include<map>
#include<iterator>
using namespace std;

class Node{
public:
    int data;
    Node *parent;
    int rankk;
};

class DisjointSet: public Node{
private:
    map<int, Node*> nodeMap;
public:
    void makeSet(int);
    void unionSets(int, int);
    int findSet(int);
    Node* findSet(Node*);
};

void DisjointSet::makeSet(int x){
    Node *temp = new Node();
    temp->data = x;
    temp->parent = temp;
    temp->rankk = 0;
    nodeMap.insert(make_pair(x, temp));
}

void DisjointSet::unionSets(int a, int b){
    Node *node1 = nodeMap.at(a);
    Node *node2 = nodeMap.at(b);

    Node *parent1 = findSet(node1);
    Node *parent2 = findSet(node2);

    if(parent1->data == parent2->data){
        cout << "nodes have same parent, or belong to same set.";
        return;
    }
    if(parent1->rankk >= parent2->rankk){
        parent2->parent = parent1;
        if(parent1->rankk==parent2->rankk)
            parent1->rankk++;
    }
    else{
        parent1->parent = parent2;
    }
}

int DisjointSet::findSet(int x){
    return findSet(nodeMap.at(x))->data;
}

Node* DisjointSet::findSet(Node *temp){
    if(temp == temp->parent){
        return temp;
    }
    temp->parent = findSet(temp->parent);
    return temp->parent;
}

int main(){
    DisjointSet ds;
    int v;
    cout << "enter initial number of vertices(or sets): "; cin >> v;
    for(int i=0; i<v; i++)
        ds.makeSet(i+1);

    ds.unionSets(1,2);
    ds.unionSets(2,3);
    ds.unionSets(4,5);
    ds.unionSets(6,7);
    ds.unionSets(5,6);
    ds.unionSets(3,7);

    for(int i=0; i<v; i++)
        cout << ds.findSet(i+1) << endl;
    return 0;
}
