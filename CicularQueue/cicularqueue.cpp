#include<iostream>
#include<vector>
using namespace std;
#define MAX_SIZE 10

class Queue{
private:
    vector<int> v = vector<int>(MAX_SIZE);
    int frontt = -1, rear = -1;

public:
    void enqueue(int);
    void dequeue();
    bool isFull();
    bool isEmpty();
    void peek();
    void print();
};
void Queue::enqueue(int x){
    if(isFull()){
        cout << "Queue's full. Overflow.\n";
        return;
    }
    if(isEmpty()){
        frontt = rear = 0;
        v[rear] = x;
    }
    else{
        rear = (rear+1)%MAX_SIZE;
        v[rear] = x;
    }
}
void Queue::dequeue(){
    if(isEmpty()){
        cout << "Queue's empty. Undeflow.\n";
        return;
    }
    if(frontt == rear)
        frontt = rear = -1;
    else
        frontt = (frontt+1)%MAX_SIZE ;
}
void Queue::peek(){
    if(isEmpty()){
        cout << "Underflow\n";
        return;
    }
    cout << "Front element: " << v[frontt] << endl;
}
bool Queue::isEmpty(){
    if(frontt==-1 && rear==-1)
        return true;
    return false;
}
bool Queue::isFull(){
    if((rear+1)%MAX_SIZE == frontt)
        return true;
    return false;
}
void Queue::print(){
    if(isEmpty()){
        cout << "Queue's empty.\n";
        return;
    }
    cout << "Queue: ";
    for(vector<int>::iterator it=v.begin(); it<v.end(); it++){
        cout << *it << " ";
    }
    cout << endl << "rear: " << rear << "   front: " << frontt << endl;
}

int main(){
    Queue q;
    int choice, value;
    char yes;

    while(true){
        cout << "\n1: enqueue\n2: dequeue\n3: peek\n4: isEmpty\n5: print\nenter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "enter value to push: ";
                cin >> value;
                q.enqueue(value); q.print();
                break;

            case 2:
                q.dequeue();q.print();
                break;

            case 3:
                q.peek();q.print();
                break;

            case 4:
                if(q.isEmpty()){
                    cout << "Queue's empty.\n";
                }
                else{
                    cout << "Queue's not empty\n";
                }
                break;

            case 5:
                q.print();
        }
    }
    return 0;
}
