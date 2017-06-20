#include<iostream>
#include<string>
#include<vector>
using namespace std;

class KMP{
string text, pattern;
vector<int> prefix;
public:
    KMP();
    void findPrefix();
    void matchSubstring();
};

KMP::KMP(){
    cout << "enter text: "; cin >> text;
    cout << "enter pattern: "; cin >> pattern;
    prefix.resize(pattern.size());
    findPrefix();
    matchSubstring();
}

void KMP::matchSubstring(){
    int i=0, j=0, index = 0;
    while(true){
        if(i==text.length() && j!=pattern.length()){
            cout << "no match!";
            return;
        }
        if(j==pattern.length()){
            cout << "match found\n";
            //cout << "match found at index: " << index;
            return;
        }
        if(text[i] == pattern[j]){
            //cout << "one\n";
            i++; j++;
        }
        else{
            if(j){
                //cout << "two\n";
                j = prefix[j-1];
                //index = i;
            }
            else{
                //cout << "three\n";
                i++;
            }
        }
    }
}

void KMP::findPrefix(){
    int i=1, j=0;
    while(i!=pattern.length()){
        if(pattern[i] == pattern[j]){
            prefix[i++] = j+1; j++;
        }
        else if(pattern[i]!=pattern[j] && !j){
            prefix[i++] = 0;
        }
        else{
            j = prefix[j-1];
        }
    }
    for(vector<int>::iterator it=prefix.begin(); it!=prefix.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    KMP k;

    return 0;
}
