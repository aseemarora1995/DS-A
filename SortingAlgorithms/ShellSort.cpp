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

void ShellSort(ivec &v){
    int h = 1;
    while(h < v.size()/3) h = 3*h+1;

    while(h >= 1){
        //cout << "h: " << h << endl;
        for(int i=h; i<v.size(); i+=h){
            for(int j=i; j>=h; j-=h){
                if(v[j] < v[j-h]){
                    //cout << v[j] << " < " << v[j-h] << endl;
                    swap(v[j], v[j-h]);
                }
                else break;
            }
        }
        h = h/3;
        print(v);
    }
}

int main(){
    int n;
    cout << "size:"; cin >> n; cout << "array: ";
    ivec v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    ShellSort(v);
    //print(v);
    return 0;
}
