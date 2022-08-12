

//Harry Patel

#include<iostream>
#include<string>
#include<list>
#include<stack>

using namespace std;

struct Person {
    string name;
    int age;

    Person(string arg1, int arg2) {
        name = arg1;
        age = arg2;
    }
};

class Node {
public:
	Person* data;
    Node* left, * right;

	void report(void);
};

class BinaryTree {
public:
	Node* root;

    void iterativeInOrder(Node* argi);
    Node* insert(Node* root, Person* arg);
};

int main() {

    BinaryTree myTree;
    myTree.root = nullptr;
    Node* curNode;
    
    char response = 'y';
    Person* newPerson = nullptr;
    string inputName;
    int inputAge = 0;

    myTree.root = new Node();
    myTree.root->data = new Person("James", 23);
    myTree.root->left = nullptr;
    myTree.root->right = nullptr;

    curNode = myTree.root;

    curNode->left = new Node();
    curNode = curNode->left;
    curNode->data = new Person("Harry", 28);
    curNode->left = nullptr;
    curNode->right = nullptr;

    curNode->right = new Node();
    curNode = curNode->right;
    curNode->data = new Person("Horton", 25);
    curNode->left = nullptr;
    curNode->right = nullptr;

    curNode = myTree.root;

    curNode->right = new Node();
    curNode = curNode->right;
    curNode->data = new Person("Natalie", 29);
    curNode->left = nullptr;
    curNode->right = nullptr;

    curNode->left = new Node();
    curNode = curNode->left;
    curNode->data = new Person("Larry", 44);
    curNode->left = nullptr;
    curNode->right = nullptr;

    curNode = myTree.root;

    curNode->right->right = new Node();
    curNode = curNode->right->right;
    curNode->data = new Person("Roman", 28);
    curNode->left = nullptr;
    curNode->right = nullptr;

    cout << "Original Report: " << endl;
    myTree.root->report();
    cout << "\n\nIn Order: " << endl;
    myTree.iterativeInOrder(myTree.root);
    cout << endl;
    
    do {
        
        cout << "\nLet's Add New Person in our Tree" << endl;

        cout << "Enter Name: ";
        getline(cin, inputName);
        cout << "Enter Age: ";
        cin >> inputAge;

        newPerson = new Person(inputName, inputAge);

        myTree.insert(myTree.root, newPerson);

        cout << "Add Again? (y or n): ";
        cin >> response;
        cin.ignore();

    } while (response == 'y' || response == 'Y');


    cout << "\n\nOriginal Report: " << endl;
    myTree.root->report();
    cout << "\n\nIn Order: " << endl;
    myTree.iterativeInOrder(myTree.root);
    cout << endl;

    //Memory Management

    delete[]myTree.root;
    myTree.root = nullptr;

    delete[] curNode;
    curNode = nullptr;

	system("pause");
	return 0;
}

void Node::report() {
    cout << data->name << ", ";
    cout << data->age << " | ";
    if (right) right->report();
    if (left) left->report();
};

void BinaryTree::iterativeInOrder(Node* argi) {
    stack<Node*> S;

    while (!S.empty() || argi != nullptr) {
        while (argi != nullptr) {
            S.push(argi);
            argi = argi->left;
        }
        argi = S.top();
        S.pop();
        cout << argi->data->name << ", ";
        cout << argi->data->age << " | ";
        argi = argi->right;
    }
}
Node* BinaryTree::insert(Node* root, Person* arg) {
    
    Node* newNode = new Node();
    newNode->data = arg;

    if (root == nullptr) {
        return newNode;
    }

    Node* up = nullptr;

    while (root != nullptr) {
        up = root;
        if (root->data->name <= arg->name) {
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    if (up->data->name <= arg->name) {
        up->right = newNode;
    }
    else {
        up->left = newNode;
    }
    return root;
}