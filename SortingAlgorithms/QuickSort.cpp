#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> ivec;

void print(ivec &);

int Partition(ivec &v, int start, int endd){
    int pivot = start;
    int next = pivot + 1;
    cout << "pivot: " << pivot << endl;
    for(int i=start+1; i<endd; i++){
        if(v[pivot] > v[i]){
            if(next < i)
                swap(v[next], v[i]);
            next++;
        }
    }
    swap(v[pivot], v[next-1]);
    pivot = next-1;
    cout << "pivot: " << pivot << endl;
    print(v);
    return pivot;

}

void QuickSort(ivec &v, int start, int endd){
    // cout << "Quicksort: " << start << "  " << endd << endl;
    int vec_size = endd-start;
    if(vec_size <= 1)
        return;
    int pivot = Partition(v, start, endd);
    QuickSort(v, start, pivot);
    QuickSort(v, pivot+1, endd);
}

void print(ivec &v){
    for(ivec::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    int n, start = 0, pivot;
    cout << "size:"; cin >> n; cout << "array: ";
    ivec v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << endl;
    pivot = Partition(v, 0, v.size());
    //cout << pivot;
    QuickSort(v, 0, pivot);
    QuickSort(v, pivot, v.size());
    print(v);
    return 0;
}
