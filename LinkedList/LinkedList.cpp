#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList: public Node{
private:
    Node* head = NULL;
public:
    void insertBeginning(int);
    void deleteBeginning();
    void insertEnd(int);
    void deleteEnd();
    void insertNth(int, int);
    void deleteNth(int);
    void print();
};

void LinkedList::insertBeginning(int x){
    Node* temp = new Node();
    temp->next = head;
    head = temp;
    temp->data = x;
}

void LinkedList::deleteBeginning(){
    if(head==NULL){
        cout << "list empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::insertEnd(int x){
    Node* temp1 = new Node();
    Node *temp = head;
    temp1->data = x;
    temp1->next = NULL;
    if(head==NULL){
        head = temp1;
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = temp1;
}

void LinkedList::deleteEnd(){
    Node *temp = head;
    Node *temp1 = head;
    if(head == NULL){
        cout << "list empty.\n";
        return;
    }
    if(head->next==NULL){
        head = NULL;
        delete temp;
        return;
    }
    while(temp->next!=NULL){
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    delete temp;
}

void LinkedList::insertNth(int x, int n){
    if(n == 0){
        insertBeginning(x);
        return;
    }
    Node* temp = new Node();
    Node* temp1 = head;
    for(int i=0; i<n-1; i++){
        temp1 = temp1->next;
    }
    temp->data = x;
    temp->next = temp1->next;
    temp1->next = temp;
}

void LinkedList::deleteNth(int n){
    if(n == 0){
        deleteBeginning();
        return;
    }
    Node* temp1 = head;
    Node* temp2 = head;
    for(int i=0; i<n-1; i++){
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

void LinkedList::print(){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main(){
    LinkedList l;
    int choice, value, n;
    while(true){
        cout << "\n1: insert_beginning\n2: delete_beginning\n3: insert_end\n4: delete_end\n5: insertNth\n";
        cout << "6: deleteNth\n7: print\nchoice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "value: ";
                cin >> value;
                l.insertBeginning(value);
                l.print();
                break;
            case 2:
                l.deleteBeginning();
                l.print();
                break;
            case 3:
                cout << "value: ";
                cin >> value;
                l.insertEnd(value);
                l.print();
                break;
            case 4:
                l.deleteEnd();
                l.print();
                break;
            case 5:
                cout << "value and position: ";
                cin >> value >> n;
                l.insertNth(value, n);
                l.print();
                break;
            case 6:
                cout << "position: ";
                cin >> n;
                l.deleteNth(n);
            case 7:
                l.print();
        }
    }
    return 0;
}
