#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
class Stack: public Node{
private:
    Node* head = NULL;
    Node* stop = NULL;
public:
    void push(int);
    void pop();
    bool isEmpty();
    void print();
    void top();
};

void Stack::top(){
    cout << "stack top: " << stop->data << endl;
}

void Stack::print(){
    if(isEmpty()){
        cout << "Stack's empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Stack: ";
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Stack::push(int x){
    Node* temp = new Node();
    Node* temp1 = head;
    stop = temp;
    temp->data = x;
    temp->next = NULL;
    if(isEmpty()){
        head = temp;
        return;
    }
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

void Stack::pop(){
    if(isEmpty()){
        cout << "Stack's empty. Nothing to pop.\n";
        return;
    }
    Node* temp = head;
    Node* temp_p = NULL;
    if(head->next==NULL){
        head = NULL;
        delete temp;
        return;
    }
    while(temp->next!=NULL){
        temp_p = temp;
        temp = temp->next;
    }
    stop = temp_p;
    temp_p->next = NULL;
    delete temp;
}

bool Stack::isEmpty(){
    if(head==NULL){
        return true;
    }
    return false;
}

int main(){
    Stack s;
    int choice, value;

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
                s.top();s.print();
                break;

            case 4:
                if(s.isEmpty())
                    cout << "Stack's empty.\n";
                else
                    cout << "Stack's not empty\n";
                break;

            case 5:
                s.print();
        }
    }
    return 0;
}
