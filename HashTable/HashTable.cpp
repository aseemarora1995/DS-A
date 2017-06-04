#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

class HashTable{
    private:
        int capacity;
        vector<list<pair<string, int> > > hashMap;
    public:
        HashTable();
        int hashIt(string);
        void addItem(string, int);
        void deleteItem(string);
        void printTable();
        void searchItem(string);
};

HashTable::HashTable(){
    cout << "yes\n";
    capacity = 13;
    hashMap.resize(capacity);
}

void HashTable::searchItem(string key){
    int index = hashIt(key);
    list<pair<string, int> >::iterator it=hashMap[index].begin();
    int flag = 0;
    while(it != hashMap[index].end()){
        if(it->first == key){
            cout << "found: " << it->first << " " << it->second << endl;
            flag = 1;
        }
        it++;
    }
    if(flag == 0){
        cout << key << " doesn't exist\n";
    }
}

int HashTable::hashIt(string key){
    int value = 0;
    for(int i=0; i<key.length(); i++){
        value += key[i];
    }
    return (value * key.length()) % capacity;
}

void HashTable::addItem(string key, int value){
    int index = hashIt(key);
    hashMap[index].push_back(make_pair(key, value));
}

void HashTable::deleteItem(string key){
    int index = hashIt(key);
    list<pair<string, int> >::iterator it=hashMap[index].begin();

    while(it != hashMap[index].end()){
        if(it->first == key){
            list<pair<string, int> >::iterator prev = it++;
            hashMap[index].erase(prev);
        }
        else it++;
    }
}

void HashTable::printTable(){
    for(int i=0; i<capacity; i++){
        cout << i << ": ";
        for(list<pair<string, int> >::iterator it = hashMap[i].begin(); it!=hashMap[i].end(); it++){
            cout << it->first << " " << it->second << ", ";
        }
        cout << endl;
    }
}

int main(){
    HashTable h;
    h.addItem("aseem", 24);
    h.addItem("aseem", 35);
    h.addItem("arora", 25);
    h.addItem("panjab",23);
    h.addItem("uni", 32);
    h.addItem("panjahb", 36);
    h.addItem("india india", 98);
    h.addItem("python", 11);
    h.addItem("ninja", 13);
    h.addItem("samurai", 94);
    h.addItem("turutle", 13);
    h.addItem("uiet", 61);
    h.addItem("si si", 32);
    h.addItem("sixtynine", 69);

    h.printTable();

    h.deleteItem("sixtynine");
    h.deleteItem("uni");
    h.deleteItem("aseem");
    h.deleteItem("ninja");

    h.printTable();

    h.searchItem("india india");
    h.searchItem("homie");
    return 0;
}
