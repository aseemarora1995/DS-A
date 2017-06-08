#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> ivec;
typedef vector<vector<int> > iivec;

class KnapSack{
public:
    void bottomUpDP(ivec &, ivec &, int);
    void topDownRecursive(ivec &, ivec &, int, int);
    int topDownRecursiveUtil(ivec &, ivec &, int, int);
    void print(iivec &);
};

void KnapSack::topDownRecursive(ivec &val, ivec&wt, int n, int W){
    cout << "answer: " << topDownRecursiveUtil(val, wt, n, W);
}

int KnapSack::topDownRecursiveUtil(ivec &val, ivec&wt, int n, int W){
    if(n==0 || W==0)
        return 0;
    if(wt[n-1] > W){
        return topDownRecursiveUtil(val, wt, n-1, W);
    }
    else{
        return max(topDownRecursiveUtil(val, wt, n-1, W), val[n-1]+topDownRecursiveUtil(val, wt, n-1, W-wt[n-1]));
    }
}

void KnapSack::print(iivec &K){
    for(int i=0; i<K.size(); i++){
        for(int j=0; j<K[i].size(); j++){
            cout << K[i][j] << " ";
        }
        cout << endl;
    }
}

void KnapSack::bottomUpDP(ivec &val, ivec &wt, int W){
    iivec K(val.size()+1, ivec(W+1));

    for(int i=0; i<K.size(); i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0){
                continue;
            }
            if(wt[i-1] <= j){
                K[i][j] = max(val[i-1]+K[i-1][j-wt[i-1]], K[i-1][j]);
            }
            else{
                K[i][j] = K[i-1][j];
            }
        }
    }
    print(K);
}

int main(){
    KnapSack k;
    ivec val = {1, 4, 5, 7};
    ivec wt = {1, 3, 4, 5};
    int W = 7;
    k.bottomUpDP(val, wt, W);
    //k.print(K);
    k.topDownRecursive(val, wt, val.size(), W);
    return 0;
}
