#include<iostream>
#include<vector>
#include<climits>
using namespace std;

typedef vector<int> ivec;

void print(ivec &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void CountingSort(ivec &v, int mul){
    int range = 10;
    ivec freq (range, 0);
    ivec output (v.size(), 0);
    //cout << "initial: "; print(v);
    for(int i=0; i<v.size(); i++){
        freq[(v[i]/mul)%range]++;
    }
    //print(freq);
    for(int i=1; i<range; i++){
        freq[i] += freq[i-1];
    }
    // print(freq);
    for(int i=v.size()-1; i>-1; i--){
        output[freq[(v[i]/mul)%range]-1] = v[i];
        freq[(v[i]/mul)%range]--;
    }
    //cout << "output: "; print(output);
    for(int i=0; i<v.size(); i++){
        v[i] = output[i];
    }
    //cout << "v: "; print(v);
}

void RadixSort(ivec &v, int maxx){
    int mul = 1;

    while(maxx){
        CountingSort(v, mul);
        maxx /= 10;
        mul *= 10;
    }
}

int main(){
    int n; int maxx=INT_MIN;
    cout << "size:"; cin >> n; cout << "array: ";
    ivec v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        maxx = max(maxx, v[i]);
    }
    cout << endl;

    RadixSort(v, maxx);
    print(v);
    return 0;
}
