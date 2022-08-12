

// Notes: Singly Linked List 
// An abstraction of an array.

#include <iostream> 
#include <string>
using namespace std;

// Class that defines the node object
template <typename T >
class Node {
private:
	T item;
	Node* nextPtr;

public:
	//constructors
	Node();
	Node(string);
	Node(string, Node*);

	//Accessor Methods
	void setItem(string);
	string getItem();
	void setNextPtr(Node*);
	Node* getNextPtr();

};

//regular c-type function for printing the Linked List
template <typename T >
void printStringList(T* beginningNodePtr);
template <typename T >
void popList(T* headPtr);
template <typename T >
void deleteListItem(T*, T*);
template <typename T >
void insertListItem(T* curNodePtr, T* newNodePtr);

int main(void) {

	// 1. Note the difference between a pointer and Node Object
	Node<string>* headPtr = nullptr;
	Node<string> myNode; //compile time instance

	Node<string>* curNodePtr = nullptr; //temp curNodePtr is often called the iterator
	Node<string>* newNodePtr = nullptr;
	// 2. Hard code a singly linked list with the head pointer above.

	// Populate the first node dynamically (at run-time)
	curNodePtr = new Node<string>("Mary");
	headPtr = curNodePtr;

	//populate the second node
	curNodePtr->setNextPtr(new Node<string>("Bill"));
	curNodePtr = curNodePtr->getNextPtr();

	//populate the third node
	curNodePtr->setNextPtr(new Node<string>("James"));
	curNodePtr = curNodePtr->getNextPtr();

	//populate the fourth node
	curNodePtr->setNextPtr(new Node<string>("Aubrey"));
	curNodePtr = curNodePtr->getNextPtr();

	cout << "Original List" << endl;
	printStringList(headPtr);

	popList(headPtr);
	cout << "Last Node deleted " << endl;
	printStringList(headPtr);

	curNodePtr = headPtr;	//This will insert the newNode after "Mary".
	insertListItem(curNodePtr, newNodePtr);
	cout << "Node inserted " << endl;
	printStringList(headPtr);

	deleteListItem(headPtr, curNodePtr);	//This will delete the curNodePtr which we inserted above.
	cout << "Deleted the given Node " << endl;
	printStringList(headPtr);


	// 3. Memory Management (Clean-up when done from front)
	while (headPtr != NULL) {
		curNodePtr = headPtr;
		headPtr = headPtr->getNextPtr();
		delete curNodePtr;
	}
	headPtr = nullptr; //both should be nullptr at the end

	printStringList(headPtr);

	system("pause");
	return (0);
}
template <typename T >
void printStringList(T* beginningNodePtr) {

	Node<string>* tempNodePtr = beginningNodePtr;

	cout << "******************" << endl;
	if (tempNodePtr == nullptr) {
		cout << "List Empty" << endl;
	}
	else {
		while (tempNodePtr->getNextPtr() != nullptr) {

			cout << tempNodePtr->getItem() << endl;
			tempNodePtr = tempNodePtr->getNextPtr();

		};
		cout << tempNodePtr->getItem() << endl;

	}
	cout << "******************" << endl;

}
template <typename T >
void popList(T* headPtr) {
	Node<string>* temp = headPtr;

	while (temp->getNextPtr()->getNextPtr() != nullptr) {
		temp = temp->getNextPtr()->getNextPtr();
	}
	delete temp->getNextPtr();
	temp->setNextPtr(nullptr);
}

template <typename T >
void deleteListItem(T* curNodePtr, T* headPtr) {
	Node<string>* temp;
	temp = curNodePtr->getNextPtr();
	curNodePtr->getItem() = temp->getItem();
	curNodePtr->setNextPtr(temp->getNextPtr());
	delete temp;
	temp = nullptr;
}

template <typename T >
void insertListItem(T* curNodePtr, T* newNodePtr) {
	Node<string>* temp;
	if (curNodePtr == nullptr) {
		return;
	}
	else {
		temp = curNodePtr->getNextPtr();
		newNodePtr = curNodePtr;
		newNodePtr->setNextPtr(new Node<string>("Inserted"));
		newNodePtr = newNodePtr->getNextPtr();
		newNodePtr->setNextPtr(temp);
	}
}

//Node Implementation
template <typename T >
Node<T>::Node()
{
	setItem(""); //default to empty string
	setNextPtr(nullptr); //default to null pointer
}

template <typename T >
Node<T>::Node(string arg)
{
	setItem(arg);
	setNextPtr(nullptr);
}

template <typename T >
Node<T>::Node(string arg, Node* argPtr)
{
	setItem(arg);
	setNextPtr(argPtr);
}

template <typename T >
void Node<T>::setItem(string arg)
{
	item = arg;
}

template <typename T >
string Node<T>::getItem()
{
	return item;
}

template <typename T >
void Node<T>::setNextPtr(Node* argPtr)
{
	nextPtr = argPtr;
}

template <typename T >
Node<T>* Node<T>::getNextPtr()
{
	return nextPtr;
}