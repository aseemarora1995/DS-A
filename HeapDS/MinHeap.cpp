#include<iostream>
#include<vector>
using namespace std;

class MinHeap{
private:
    vector<int> v;
public:
    void addElement(int);
    void findMin();
    void print();
};

void MinHeap::print(){
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void MinHeap::addElement(int x){
    v.push_back(x);
    int index = v.size()-1;
    cout << "index: " << index << endl;
    int index_p;
    while(true){
        if(index%2==0) index_p = index/2 - 1;
        else index_p = index/2;
        if(v[index] < v[index_p]){
            swap(v[index], v[index_p]);
            index = index_p;
        }
        else{
            break;
        }
    }
    print();
}

void MinHeap::findMin(){
    if(v.empty()){
        cout << "heap empty\n";
        return;
    }
    int minimum = v.front();
    // cout << "minimum: " << minimum << endl;
    v[0] = v.back();
    v.pop_back();
    // cout << "size: " << v.size() << endl;
    print();
    int child1, child2, child;
    int index = 0;
    while(true){
        //cout << "yes\n";
        child1 = 2*index+1; child2 = 2*index+2;
        if(child1 > v.size()) break;
        //cout << index << " " << child1 << " " << child2 << endl;
        if(v[child1]>v[child2]) child = child2;
        else child = child1;

        if(v[index] > v[child]){
            swap(v[index], v[child]);
            index = child;
        }
        else
            break;
    }
}

int main(){
    int x;
    MinHeap heap;
    heap.addElement(4);
    heap.addElement(4);
    heap.addElement(8);
    heap.addElement(9);
    heap.addElement(4);
    heap.addElement(12);
    heap.addElement(9);
    heap.addElement(11);
    heap.addElement(13);
    while(true){
        char ch;
        cin >> ch;
        heap.findMin();
        heap.print();
    }

    return 0;
}
