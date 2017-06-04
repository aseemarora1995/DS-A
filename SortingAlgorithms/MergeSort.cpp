#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> veci;

veci Merge(veci a, veci b){
    int ia = 0, ib = 0; veci c;

    while(ia < a.size() && ib < b.size()){
        if(a[ia] < b[ib])
            c.push_back(a[ia++]);
        else
            c.push_back(b[ib++]);
    }

    while(ia < a.size())
        c.push_back(a[ia++]);
    while(ib < b.size())
        c.push_back(b[ib++]);
    return c;
}

veci MergeSort(veci v, int start, int n){
    int middle = n/2, vec_size = v.size();

    veci a (v.begin(), v.begin()+middle);
    veci b (v.begin()+middle, v.end());

    if(vec_size <= 1){
        return v;
    }
    a = MergeSort(a, 0, a.size());
    b = MergeSort(b, 0, b.size());
    veci c = Merge(a, b);
    return c;
}

int main(){
    int n, start = 0;
    cout << "size: "; cin >> n;
    veci v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << endl;

    v = MergeSort(v, 0, start);

    for(veci::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
