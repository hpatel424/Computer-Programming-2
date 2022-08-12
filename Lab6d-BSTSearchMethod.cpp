

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
    Node* search(Node* subTreePtr, int target);
    int findDepth(int);
};


int main(void) {

    char ur = 'y';
    int input;
    BinaryTree myFirstTree;
    myFirstTree.root = nullptr;

    myFirstTree.insert(8);
    myFirstTree.insert(3);
    myFirstTree.insert(10);
    myFirstTree.insert(1);
    myFirstTree.insert(6);
    myFirstTree.insert(14);
    myFirstTree.insert(4);
    myFirstTree.insert(7);
    myFirstTree.insert(13);

    cout << "My First Tree " << endl;
    if (myFirstTree.root != nullptr) {
        myFirstTree.root->report();
        cout << endl;
    }
    else {
        cout << "Empty Tree" << endl;
    }

    do {

        cout << "Enter a target to search: ";
        cin >> input;

        if (myFirstTree.search(myFirstTree.root, input) != nullptr) {
            cout << "Target Found at " << myFirstTree.search(myFirstTree.root, input) << endl;
        }
        else {
            cout << "Target NOT found" << endl;
        }

        cout << "Search again?(y or n)";
        cin >> ur;
        cout << endl;

    } while (ur == 'y' || ur == 'Y');

   

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

Node* BinaryTree::search(Node* subTreePtr, int target) {
    if (subTreePtr == nullptr) {
        return nullptr;
    }
    else if (subTreePtr->data == target) {
        return subTreePtr;
    }
    else if (subTreePtr->data > target) {
        return search(subTreePtr->left, target);
    }
    else {
        return search(subTreePtr->right, target);
    }
}

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