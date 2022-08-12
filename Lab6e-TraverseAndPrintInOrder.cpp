

//Harry Patel
// Basic notes on Binary Trees

#include<iostream>
#include<string>
#include<list>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left, * right;

    int findDepth(int);
    void report(void);

    void iterativeInOrder(Node* argi);
    void inOrder(Node* argr);
};

class BinaryTree {
public:
    Node* root;

    int findDepth(int);
};


int main(void) {

    // create an Empty Tree

    BinaryTree myFirstTree;
    Node* curNode;
    myFirstTree.root = nullptr;

    //populate the first node (root) (Level 0)

    myFirstTree.root = new Node();
    myFirstTree.root->data = 8;
    myFirstTree.root->left = nullptr;
    myFirstTree.root->right = nullptr;

    curNode = myFirstTree.root;

    //populate the second node (Level 1)

    curNode->left = new Node();
    curNode = curNode->left;
    curNode->data = 3;
    curNode->left = nullptr;
    curNode->right = nullptr;

    //populate the third node (Level 2)

    curNode->right = new Node();
    curNode = curNode->right;
    curNode->data = 6;
    curNode->left = nullptr;
    curNode->right = nullptr;

    //populate the 4th node(Level 3)

    curNode->right = new Node();
    curNode = curNode->right;
    curNode->data = 7;
    curNode->left = nullptr;
    curNode->right = nullptr;

    curNode = myFirstTree.root;
    curNode->left->left = new Node();
    curNode = curNode->left->left;
    curNode->data = 1;
    curNode->left = nullptr;
    curNode->right = nullptr;

    curNode = myFirstTree.root;
    curNode->left->right->left = new Node();
    curNode = curNode->left->right->left;
    curNode->data = 4;
    curNode->left = nullptr;
    curNode->right = nullptr;

    curNode = myFirstTree.root;
    curNode->right = new Node();
    curNode = curNode->right;
    curNode->data = 10;
    curNode->left = nullptr;
    curNode->right = nullptr;

    curNode->right = new Node();
    curNode = curNode->right;
    curNode->data = 14;
    curNode->left = nullptr;
    curNode->right = nullptr;

    curNode->left = new Node();
    curNode = curNode->left;
    curNode->data = 13;
    curNode->left = nullptr;
    curNode->right = nullptr;

    cout << "Original: " << endl;
    myFirstTree.root->report();
    //cout << "\nDepth = " << myFirstTree.findDepth(14) << endl;

    cout << "\nRecursive: " << endl;
    myFirstTree.root->inOrder(myFirstTree.root);

    cout << "\nIterative: " << endl;
    myFirstTree.root->iterativeInOrder(myFirstTree.root);
    cout << endl;

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

void Node::iterativeInOrder(Node* argi) {
    stack<Node*> S;

    while (!S.empty() || argi != nullptr) {
        while(argi != nullptr) {
            S.push(argi);
            argi = argi->left;
        }
        argi = S.top();
        S.pop();
        cout << argi->data << " ";
        argi = argi->right;
    }
}

void Node::inOrder(Node* argr) {

    if (argr==nullptr){
        return;
    }
    inOrder(argr->left);
    cout << argr->data << " ";
    inOrder(argr->right);
}