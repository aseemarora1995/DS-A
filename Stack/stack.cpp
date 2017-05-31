#include<iostream>
#include<vector>
using namespace std;
#define MAX_SIZE 11

class Stack{
private:
    vector<int> v = vector<int>(MAX_SIZE);
    int top = -1;

    //Stack() : v(MAX_SIZE) { }

public:

    void push(int x){
        if(top == MAX_SIZE-1){
            cout << "Stack full. No push possible.\n";
            return;
        }
        v[++top] = x;
    }

    void pop(){
        if(top == -1){
            cout << "Stack empty. No pop possible.\n";
            return;
        }
        top--;
    }

    void top_stack(){
        if(top == -1){
            cout << "Stack empty. Nothing at top.\n";
            return;
        }
        cout << "top: " << v[top] << endl;
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        return false;
    }

    void print(){
        cout << "Stack: ";
        for(vector<int>::iterator it = v.begin(); it!=v.begin()+top+1; it++){
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack s;
    int choice, value;
    char yes;


    while(true){
        cout << "1: push\n2: pop\n3: top\n4: isEmpty\n5: print\nenter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "enter value to push: ";
                cin >> value;
                s.push(value); s.print();
                break;

            case 2:
                s.pop();s.print();
                break;

            case 3:
                s.top_stack();s.print();
                break;

            case 4:
                if(s.isEmpty()){
                    cout << "Stack's empty.\n";
                }
                else{
                    cout << "Stack's not empty\n";
                }
                break;

            case 5:
                s.print();
        }
        /*
        cout << "go again?[Y/n]: ";
        cin >> yes;
        if(yes == 'n')
            break;
        */
    }
}
