

//Harry Patel

// Basic notes on Binary Trees

#include<iostream>
#include<string>
#include<list>

using namespace std;

class Node {
public:
    int data;
    Node* left, * right;

    int findDepth(int);
    void report(void);
};

class BinaryTree {
public:
    Node* root;

    void insert(int arg);
    Node* insertInorder(Node* subTreePtr, Node* newNodePtr);
    int findDepth(int);
};


int main(void) {

    char response = 'y';
    BinaryTree myFirstTree;
    myFirstTree.root = nullptr;
    int input;

    do {

        cout << "Enter an integer to insert in tree: ";
        cin >> input;

        myFirstTree.insert(input);

        if (myFirstTree.root != nullptr) {
            myFirstTree.root->report();
        }
        else {
            cout << "Empty Tree" << endl;
        }

        cout << "\nInsert again (y or n)?";
        cin >> response;
        cin.ignore();

    } while (response == 'y' || response == 'Y');
  
    system("pause");
    return(0);
}

int BinaryTree::findDepth(int i) {
    if (root)
        return (root->findDepth(i));
    else {
        return(-1);
    }
};

int Node::findDepth(int i) {
    if (i == data) return(0);

    int d;

    if (i < data) {
        if (left) d = left->findDepth(i);
        else d = -1;
    }
    if (i > data) {
        if (right) d = right->findDepth(i);
        else d = -1;
    }
    if (d == -1) return(-1);
    else return(d + 1);
};

void Node::report() {
    cout << data << " ";
    if (right) right->report();
    if (left) left->report();
};

void BinaryTree::insert(int arg) {
    
    Node* newNodePtr = new Node();
    newNodePtr->data = arg;
    root = insertInorder(root, newNodePtr);
}

Node* BinaryTree::insertInorder(Node* subTreePtr, Node* newNodePtr) {
    
    Node* tempPtr;

    if (subTreePtr == nullptr) {
        return newNodePtr;
    }
    else if (subTreePtr->data > newNodePtr->data) {
        tempPtr = insertInorder(subTreePtr->left, newNodePtr);
        subTreePtr->left = tempPtr;
    }
    else {
        tempPtr = insertInorder(subTreePtr->right, newNodePtr);
        subTreePtr->right = tempPtr;
    }
    return subTreePtr;
}