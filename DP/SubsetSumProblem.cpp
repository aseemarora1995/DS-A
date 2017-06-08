#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> ivec;
typedef vector<bool> bvec;
typedef vector<bvec> bbvec;
class SubsetSum{
public:
    bool subsetSum(ivec &, int);
    void print(bbvec &);
};

void SubsetSum::print(bbvec &temp){
    cout << "   ";
    for(int i=0; i<temp[0].size(); i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i=0; i<temp.size(); i++){
        cout << i << ": ";
        for(int j=0; j<temp[0].size(); j++){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
}

bool SubsetSum::subsetSum(ivec &val, int total){
    bbvec temp(val.size()+1, bvec(total+1));
    temp[0][0] = 1;
    for(int i=1; i<temp.size(); i++){
        for(int j=0; j<temp[0].size(); j++){
            if(j==0){
                temp[i][j] = 1;
                continue;
            }
            if(val[i-1] > j){
                temp[i][j] = temp[i-1][j];
            }
            else{
                temp[i][j] = temp[i-1][j] || temp[i-1][j-val[i-1]];
            }

        }
    }
    print(temp);
    return temp[val.size()][total];
}

int main(){
    int arr[] = {2,3,7,8,10}, total = 11;
    vector<int> v (arr, arr+5);
    SubsetSum s;
    cout << s.subsetSum(v, total);
}
