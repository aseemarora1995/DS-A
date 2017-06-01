#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};

class BST: public Node{
private:
    queue<Node*> q;
public:
    Node* root = NULL;
    Node* insert_data(Node*, int);
    void preOrder(Node*);
    void inOrder(Node*);
    void postOrder(Node*);
    void levelOrder(Node*);
    void print(Node*);
    Node* delete_node(Node*, int);
    Node* findMinRight(Node*);

};

Node* BST::findMinRight(Node* root){
    if(root->left==NULL)
        return root;
    findMinRight(root->left);
}

Node* BST::delete_node(Node* root, int data){
    if(root==NULL)
        return root;
    if(data < root->data){
        root->left = delete_node(root->left, data);
    }
    else if(data > root->data){
        root->right = delete_node(root->right, data);
    }
    else{ // data found
        Node *temp = root;
        // no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            root = NULL;
        }
        // single child
        else if(root->left==NULL){
            root = root->right;
            delete temp;
        }
        else if(root->right==NULL){
            root = root->left;
            delete temp;
        }
        // 2 children
        else{
            Node *temp1 = findMinRight(root->right);
            cout << "right_min: " << temp1->data << endl;
            root->data = temp1->data;
            root->right = delete_node(root->right, temp1->data);
        }
    }
    return root;
}

void BST::levelOrder(Node* temp){
    q.push(temp);
    while(!q.empty()){
        temp = q.front();
        cout << temp->data << " ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
        q.pop();
    }
}

void BST::preOrder(Node *temp){
    if(temp==NULL)
        return;
    cout << temp->data << " ";
    preOrder(temp->left);
    preOrder(temp->right);
}
void BST::inOrder(Node *temp){
    if(temp==NULL)
        return;
    inOrder(temp->left);
    cout << temp->data << " ";
    inOrder(temp->right);
}
void BST::postOrder(Node *temp){
    if(temp==NULL)
        return;
    postOrder(temp->left);
    postOrder(temp->right);
    cout << temp->data << " ";
}
void BST::print(Node* temp){
    cout << "preorder: ";
    preOrder(temp);
    cout << endl << "inorder: ";
    inOrder(temp);
    cout << endl << "postorder: ";
    postOrder(temp);
    cout << endl << "levelorder: ";
    levelOrder(temp);
}

Node* BST::insert_data(Node* root, int data){
    if(root==NULL){
        Node* temp = new Node();
        temp->data = data;
        temp->left = temp->right = NULL;
        root = temp;
    }
    else if(data <= root->data)
        root->left = insert_data(root->left, data);

    else if(data > root->data)
        root->right = insert_data(root->right, data);

    return root;
}

int main(){
    BST tree;
    int choice, data;
    while(true){
        cout << "\n1: insert\n2: print\n3: delete\n4: find_min_right\n";
        cout << "choice: ";
        cin >> choice;
        switch(choice){
        case 1:
            cout << "data: ";
            cin >> data;
            tree.root = tree.insert_data(tree.root, data);
            break;
        case 2:
            tree.print(tree.root);
            break;
        case 3:
            cout << "data: ";
            cin >> data;
            tree.root = tree.delete_node(tree.root, data);
        }
    }
    return 0;
}
