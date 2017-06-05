#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> ivec;

void print(ivec &v){
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void Heapify(ivec &v, int current=0){
    int child1, child2, child;
    child = current;
    child1 = 2*current+1; child2 = 2*current+2;
    if(v[child1] < v[child] && child1 < v.size()){
        child = child1;
    }
    if(v[child2] < v[child] && child2 < v.size()){
        child = child2;
    }
    if(current!=child){
        swap(v[current], v[child]);
        Heapify(v, child);
    }
    /*while(true){
        child = current;
        child1 = 2*current+1; child2 = 2*current+2;
        if(v[child1] < v[child] && child1 < v.size()){
            child = child1;
        }
        if(v[child2] < v[child] && child2 < v.size()){
            child = child2;
        }
        if(current==child) break;
        swap(v[current], v[child]);
        current = child;
    }*/
}

void HeapSort(ivec &v){
    for(int i=v.size()-1; i>-1; i--){
        Heapify(v, i);
    }
    print(v);

    while(v.size()>0){
        cout << v[0] << " ";
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        Heapify(v);
        //print();
    }
}

int main(){
    int n;
    cout << "size:"; cin >> n; cout << "array: ";
    ivec v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    print(v);
    HeapSort(v);
    return 0;
}
