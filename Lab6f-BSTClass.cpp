

//Harry Patel

#include<iostream>
#include<string>
#include<list>
#include<stack>

using namespace std;

template<typename T>
class Node {
private:
    T data;
    Node* left, * right;
public:

    T getData(void);
    void setData(T argData);

    Node* getLeftPtr(void);
    void setLeftPtr(Node* leftPtr);

    Node* getRightPtr(void);
    void setRightPtr(Node* rightPtr);

    int findDepth(T i);
    void report(void);
};

template<typename T>
class BinaryTree {
private:
    Node<T>* root;
public:

    Node<T>* getRoot(void);
    void setRoot(Node<T>* argRoot);

    int findDepth(T i);
    void insert(T arg);
    Node<T>* insertInorder(Node<T>* subTreePtr, Node<T>* newNodePtr); 
    Node<T>* search(Node<T>* subTreePtr, T target);
    void printInOrder(Node<T>* root);
    void printPostOrder(Node<T>* root);
    void remove(Node<T>* root);

};


int main(void) {

    BinaryTree<string> myFirstTree;
    myFirstTree.setRoot(nullptr);
    
    BinaryTree<int> myNumberTree;
    myNumberTree.setRoot(nullptr);

    char response = 'y';
    string input;
   
    myNumberTree.insert(8);
    myNumberTree.insert(3);
    myNumberTree.insert(10);
    myNumberTree.insert(1);
    myNumberTree.insert(6);
    myNumberTree.insert(14);
    myNumberTree.insert(4);
    myNumberTree.insert(7);
    myNumberTree.insert(13);

   
    cout << "My Number Tree \n\nOriginal: " << endl;
    myNumberTree.getRoot()->report();

    cout << "\n\nIn order: " << endl;
    myNumberTree.printInOrder(myNumberTree.getRoot());

    cout << "\n\nPost Order: " << endl;
    myNumberTree.printPostOrder(myNumberTree.getRoot());

    cout << "\n\nSearch function: " << endl;
    if (myNumberTree.search(myNumberTree.getRoot(), 7)) {
        cout << "7 found at " << myNumberTree.search(myNumberTree.getRoot(), 7) << endl;
    }
    else {
        cout << "Error 404! NOT found" << endl;
    }
    cout << "\nDepth = " << myNumberTree.findDepth(13) << endl;

    cout << "\n***********************************************" << endl;
     

    do {

        cout << "Enter a string to insert in tree: ";
        getline(cin, input);

        myFirstTree.insert(input);


        cout << "\nInserst again? (y or n): ";
        cin >> response;
        cin.ignore();
    } while (response == 'y' || response == 'Y');
    
    cout << "\n***********************************************" << endl;

    cout << "User String Tree: " << endl;
    cout << "\nIn Order: " << endl;
    myFirstTree.printInOrder(myFirstTree.getRoot());

    cout << "\n\nPost Order: " << endl;
    myFirstTree.printPostOrder(myFirstTree.getRoot());

    cout << endl << endl;

    cout << "\n***********************************************" << endl;

    //Memory Management
    myFirstTree.remove(myFirstTree.getRoot());
    myNumberTree.remove(myNumberTree.getRoot());

    system("pause");
    return(0);
}



template<typename T>
T Node<T>::getData(void) {
    return data;
}

template<typename T>
void Node<T>::setData(T argData) {
    data = argData;
}

template<typename T>
Node<T>* Node<T>::getLeftPtr(void) {
    return left;
}

template<typename T>
void Node<T>::setLeftPtr(Node<T>* leftPtr) {
    left = leftPtr;
}

template<typename T>
Node<T>* Node<T>::getRightPtr(void) {
    return right;
}

template<typename T>
void Node<T>::setRightPtr(Node<T>* rightPtr) {
    right = rightPtr;
}

template<typename T>
Node<T>* BinaryTree<T>::getRoot(void) {
    return root;
}
template<typename T>
void BinaryTree<T>::setRoot(Node<T>* argRoot) {
    root = argRoot;
}


//***************Find Depth************************
template<typename T>
int BinaryTree<T>::findDepth(T i) {
    if (root)
        return (root->findDepth(i));
    else {
        return(-1);
    }
};
template<typename T>
int Node<T>::findDepth(T i) {
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

//*************report***************************
template<typename T>
void Node<T>::report() {
    cout << data << " ";
    if (right) right->report();
    if (left) left->report();
};


//*************************insert******************
template<typename T>
void BinaryTree<T>::insert(T arg) {

    Node<T>* newNodePtr = new Node<T>();
    newNodePtr->setData(arg);
    root = insertInorder(root, newNodePtr);
}
template<typename T>
Node<T>* BinaryTree<T>::insertInorder(Node<T>* subTreePtr, Node<T>* newNodePtr) {

    Node<T>* tempPtr;

    if (subTreePtr == nullptr) {
        return newNodePtr;
    }
    else if (subTreePtr->getData() > newNodePtr->getData()) {
        tempPtr = insertInorder(subTreePtr->getLeftPtr(), newNodePtr);
        subTreePtr->setLeftPtr(tempPtr);
    }
    else {
        tempPtr = insertInorder(subTreePtr->getRightPtr(), newNodePtr);
        subTreePtr->setRightPtr(tempPtr);
    }
    return subTreePtr;
}

//**********************search************************
template<typename T>
Node<T>* BinaryTree<T>::search(Node<T>* subTreePtr, T target) {
    if (subTreePtr == nullptr) {
        return nullptr;
    }
    else if (subTreePtr->getData() == target) {
        return subTreePtr;
    }
    else if (subTreePtr->getData() > target) {
        return search(subTreePtr->getLeftPtr(), target);
    }
    else {
        return search(subTreePtr->getRightPtr(), target);
    }
}

//**************print in order***************************

template<typename T>
void BinaryTree<T>::printInOrder(Node<T>* root) {

    stack<Node<T>*> S;
    
    while (!S.empty() || root != nullptr) {
        while(root != nullptr) {
            S.push(root);
            root = root->getLeftPtr();
        }

        root = S.top();
        S.pop();
        cout << root->getData() << " ";
        root = root->getRightPtr();
    }
}

//**************print Post order***************************

template<typename T>
void BinaryTree<T>::printPostOrder(Node<T>* root) {

    stack<Node<T>*> S1, S2;
    Node<T>* temp;

    S1.push(root);

    while (!S1.empty()) {
        temp = S1.top();
        S1.pop();
        S2.push(temp);

        if (temp->getLeftPtr()) {
            S1.push(temp->getLeftPtr());
        }
        if (temp->getRightPtr()) {
            S1.push(temp->getRightPtr());
        }
    }

    while (!S2.empty()) {
        temp = S2.top();
        S2.pop();
        cout << temp->getData() << " ";
    }
}

//****************remove**************

template<typename T>
void BinaryTree<T>::remove(Node<T>* root) {
   
    if (root != nullptr) {
        remove(root->getLeftPtr());
        remove(root->getRightPtr());
        delete root;
    }
}