#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> ivec;
typedef vector<ivec> iivec;
class LCS{
public:
    int bottomUpDP(string, string);
    void print(iivec &);
    int topDownRecursive(string &, string &, int, int);
};

int LCS::topDownRecursive(string &s1, string &s2, int i, int j){
    if(i < 0 || j < 0)
        return 0;
    if(s1[i] == s2[j])
        return topDownRecursive(s1, s2, i-1, j-1) + 1;
    else
        return max(topDownRecursive(s1, s2, i-1, j), topDownRecursive(s1, s2, i, j-1));
}

int LCS::bottomUpDP(string s1, string s2){
    iivec temp(s1.length()+1, ivec(s2.length()+1));

    for(int i=1; i<s1.length()+1; i++){
        for(int j=1; j<s2.length()+1; j++){
            if(s1[i-1]==s2[j-1])
                temp[i][j] = temp[i-1][j-1] + 1;
            else
                temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
        }
    }
    print(temp);
    return temp[s1.length()][s2.length()];
}

void LCS::print(iivec &K){
    for(int i=0; i<K.size(); i++){
        for(int j=0; j<K[i].size(); j++){
            cout << K[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    LCS l;
    string s2 = "abcdaf", s1 = "acbcf";
    cout << s1 << endl << s2 << endl;
    cout << "bottomUp: " << l.bottomUpDP(s1, s2) << endl;
    cout << "topDown: " << l.topDownRecursive(s1, s2, s1.length()-1, s2.length()-1);
    return 0;
}
