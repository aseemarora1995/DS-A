#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

class RabinKarp{
    string text, pattern;
    int pHash=0, sHash, prime=101;
public:
    RabinKarp();
    int findHash(string &, int, int);
    int recalculateHash(int, int);
    bool checkEqual(int, int);
};

int RabinKarp::recalculateHash(int olds, int newe){
    //cout << "recalculating\n";
    sHash = sHash - int(text[olds]);
    sHash /= prime;
    sHash += int(text[newe])*pow(prime, pattern.length()-1);
    //cout << "::" << sHash << endl;
    //return sHash;
}

bool RabinKarp::checkEqual(int s, int e){
    //cout << "check equal\n";
    for(int i=0; i<pattern.length(); i++){
        //cout << pattern[i] << "<>" << text[i+s] << endl;
        if(pattern[i] != text[i+s])
            return false;
    }
    return true;
}

int RabinKarp::findHash(string &p, int s, int e){
    int temp=0;
    for(int i=0; i<e-s; i++){
        //cout << ">> " << int(p[i]) << endl;
        //cout << ">>>" << i << " " << prime << " " <<pow(prime, i) << endl;
        //cout << "temp:" << temp << "   pro: " << int(p[i])*pow(prime, i) << endl;
        temp = temp + int(p[i])*pow(prime, i);
        //cout << "temp: " << temp << endl;
    }
    //cout << "::" << temp << endl;
    return temp;
}

RabinKarp::RabinKarp(){
    cout << "enter text: "; cin >> text;
    cout << "enter pattern: "; cin >> pattern;
    //cout << int(pattern[0]) << endl;
    int pl = pattern.length();
    int tl = text.length();
    //cout << "tl: " << tl << endl << "pl: " << pl << endl;
    pHash = findHash(pattern, 0, pl);
    sHash = findHash(text, 0, pl);

    for(int i=1; i<tl-pl+2; i++){
        if(sHash == pHash && checkEqual(i-1, i-1+pl)){
            cout << i-1 << endl;
            return;
        }
        if(i < tl-pl+1){
            //cout << i-1 << "<><>" << i-1+pl << endl;
            recalculateHash(i-1, i-1+pl);
        }
    }
    cout << "-1\n";
    return;
}

int main(){
    RabinKarp rk;

    return 0;
}
