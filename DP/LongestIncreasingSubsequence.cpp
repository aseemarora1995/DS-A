#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef vector<int> ivec;

class LIS{
public:
    void lis(ivec &);
};

void LIS::lis(ivec &v){
    ivec temp(v.size(), 1);

    for(int i=1; i<v.size(); i++){
        for(int j=0; j<i; j++){
            if(v[j] < v[i])
                temp[i] = max(temp[i], temp[j]+1);
        }
    }
    for(int i=0; i<temp.size(); i++){
        cout << temp[i] << " ";
    }
}

int main(){
    LIS l;
    int n; cout << "size: " ; cin >> n;
    ivec v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    l.lis(v);
    return 0;
}
